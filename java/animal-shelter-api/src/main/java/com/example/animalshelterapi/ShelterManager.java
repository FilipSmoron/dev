package com.example.animalshelterapi;

import org.springframework.stereotype.Component;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Optional;

@Component
public class ShelterManager {

    private final ShelterRepository shelterRepository;
    private Map<String, AnimalShelter> shelters;

    public ShelterManager(ShelterRepository shelterRepository) {
        this.shelterRepository = shelterRepository;
        this.shelters = new HashMap<>();
        loadFromDatabase();
    }

    private void loadFromDatabase() {
        shelterRepository.findAll().forEach(s -> shelters.put(s.getName(), s));
    }

    public boolean addAnimalToShelter(String shelterName, Animal animal) {
        AnimalShelter shelter = shelters.get(shelterName);
        if (shelter == null) {
            throw new IllegalArgumentException("Shelter not found.");
        }
        return shelter.addAnimal(animal);
    }

    public void removeAnimalFromShelter(String shelterName, String animalId) {
        AnimalShelter shelter = shelters.get(shelterName);
        if (shelter == null) {
            throw new IllegalArgumentException("Shelter not found.");
        }
        shelter.removeAnimal(animalId);
    }

    public Optional<Animal> getAnimalFromShelter(String shelterName, String animalId) {
        AnimalShelter shelter = shelters.get(shelterName);
        if (shelter == null) {
            throw new IllegalArgumentException("Shelter not found.");
        }
        return shelter.getAnimal(animalId);
    }

    public List<Animal> getAnimalsInShelter(String shelterName) {
        AnimalShelter shelter = shelters.get(shelterName);
        if (shelter == null) {
            throw new IllegalArgumentException("Shelter not found.");
        }
        return shelter.getAnimals();
    }

    public void addShelter(String name, int capacity) {
        if (shelters.containsKey(name)) {
            throw new IllegalArgumentException("Shelter with this name already exists.");
        }
        AnimalShelter shelter = new AnimalShelter(name, capacity);
        shelters.put(name, shelter);
        shelterRepository.save(shelter);
    }

    public void removeShelter(String name) {
        if (!shelters.containsKey(name)) {
            throw new IllegalArgumentException("Shelter not found.");
        }
        shelters.remove(name);
        shelterRepository.deleteById(name);
    }

    public List<String> getAllShelterNames() {
        return List.copyOf(shelters.keySet());
    }

    public String generateShelterCSV(String shelterName) {
        AnimalShelter shelter = shelters.get(shelterName);
        if (shelter == null) {
            throw new IllegalArgumentException("Shelter not found.");
        }
        return shelter.generateCSV();
    }

    public double getShelterFillPercentage(String shelterName) {
        AnimalShelter shelter = shelters.get(shelterName);
        if (shelter == null) {
            throw new IllegalArgumentException("Shelter not found.");
        }
        return shelter.getFillPercentage();
    }

    public void addRating(String shelterName, int rating) {
        AnimalShelter shelter = shelters.get(shelterName);
        if (shelter == null) {
            throw new IllegalArgumentException("Shelter not found.");
        }
        shelter.addRating(rating);
    }
}
