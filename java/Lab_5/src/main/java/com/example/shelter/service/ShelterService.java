package com.example.shelter.service;

import com.example.shelter.exception.ResourceNotFoundException;
import com.example.shelter.model.Animal;
import com.example.shelter.model.Rating;
import com.example.shelter.model.Shelter;
import com.example.shelter.repository.AnimalRepository;
import com.example.shelter.repository.RatingRepository;
import com.example.shelter.repository.ShelterRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class ShelterService {

    private final ShelterRepository shelterRepository;
    private final AnimalRepository animalRepository;
    private final RatingRepository ratingRepository;

    @Autowired
    public ShelterService(ShelterRepository shelterRepository, AnimalRepository animalRepository, RatingRepository ratingRepository) {
        this.shelterRepository = shelterRepository;
        this.animalRepository = animalRepository;
        this.ratingRepository = ratingRepository;
    }

    // Metody związane z schroniskami

    public Shelter addShelter(Shelter shelter) {
        return shelterRepository.save(shelter);
    }

    public List<Shelter> getAllShelters() {
        return shelterRepository.findAll();
    }

    public Shelter getShelterById(Long id) {
        return shelterRepository.findById(id).orElse(null);
    }

    public boolean deleteShelter(Long id) {
        Shelter shelter = getShelterById(id);
        if (shelter != null) {
            shelterRepository.delete(shelter);
            return true;
        }
        return false;
    }

    // Metody związane ze zwierzętami

    public Animal addAnimal(Animal animal) {
        return animalRepository.save(animal);
    }

    public Animal getAnimalById(Long id) {
        return animalRepository.findById(id)
                .orElseThrow(() -> new ResourceNotFoundException("Nie znaleziono zwierzęcia o ID: " + id));
    }

    public boolean deleteAnimal(Long id) {
        Animal animal = getAnimalById(id);
        if (animal != null) {
            animalRepository.delete(animal);
            return true;
        }
        return false;
    }

    public List<Animal> getAnimalsInShelter(Long shelterId) {
        Shelter shelter = getShelterById(shelterId);
        if (shelter != null) {
            return animalRepository.findByShelter(shelter);
        }
        return null;
    }

    // Metody związane z ocenami

    public Rating addShelterRating(Long shelterId, Integer rating) {
        Shelter shelter = getShelterById(shelterId);
        if (shelter != null) {
            Rating newRating = new Rating(shelter, rating);
            return ratingRepository.save(newRating);
        }
        return null;
    }

    public Double calculateShelterAverageRating(Long shelterId) {
        Shelter shelter = getShelterById(shelterId);
        if (shelter != null) {
            List<Rating> ratings = ratingRepository.findByShelter(shelter);
            if (!ratings.isEmpty()) {
                double sum = ratings.stream().mapToDouble(Rating::getRating).sum();
                return sum / ratings.size();
            }
        }
        return null;
    }

    // Metody związane z eksportem danych

    public String generateSheltersCsv() {
        List<Shelter> shelters = getAllShelters();
        if (!shelters.isEmpty()) {
            StringBuilder csvContent = new StringBuilder("Id;Name;Location;Capacity\n");
            shelters.forEach(shelter -> csvContent.append(shelter.getId()).append(";").append(shelter.getName()).append(";").append(shelter.getLocation()).append(";").append(shelter.getCapacity()).append("\n"));
            return csvContent.toString();
        }
        return null;
    }

    // Metody związane z wyszukiwaniem danych

    public List<Animal> findAnimalsBySpecies(String species) {
        return animalRepository.findBySpecies(species);
    }

    public List<Shelter> findSheltersByLocation(String location) {
        return shelterRepository.findByLocation(location);
    }

    public List<Animal> findAnimalsByAgeRange(int minAge, int maxAge) {
        return animalRepository.findByAgeBetween(minAge, maxAge);
    }

    public Double calculateShelterFillPercentage(Long shelterId) {
        Shelter shelter = getShelterById(shelterId);
        if (shelter != null) {
            List<Animal> animals = getAnimalsInShelter(shelterId);
            if (!animals.isEmpty()) {
                double fillPercentage = (double) animals.size() / shelter.getCapacity() * 100;
                return fillPercentage;
            }
        }
        return null;
    }

    public Animal transferAnimalToShelter(Long animalId, Long targetShelterId) {
        Animal animal = getAnimalById(animalId);
        Shelter targetShelter = getShelterById(targetShelterId);
        if (animal != null && targetShelter != null) {
            animal.setShelter(targetShelter);
            return animalRepository.save(animal);
        }
        return null;
    }
}