package com.example.animalshelterapi;

import org.springframework.stereotype.Service;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Optional;

@Service
public class ShelterService {

    private final ShelterManager shelterManager;

    public ShelterService(ShelterManager shelterManager) {
        this.shelterManager = shelterManager;
    }

    public boolean addAnimalToShelter(String shelterName, Animal animal) {
        return shelterManager.addAnimalToShelter(shelterName, animal);
    }

    public void removeAnimalFromShelter(String shelterName, String animalId) {
        shelterManager.removeAnimalFromShelter(shelterName, animalId);
    }

    public Optional<Animal> getAnimalFromShelter(String shelterName, String animalId) {
        return shelterManager.getAnimalFromShelter(shelterName, animalId);
    }

    public List<Animal> getAnimalsInShelter(String shelterName) {
        return shelterManager.getAnimalsInShelter(shelterName);
    }

    public void addShelter(String name, int capacity) {
        shelterManager.addShelter(name, capacity);
    }

    public void removeShelter(String name) {
        shelterManager.removeShelter(name);
    }

    public List<String> getAllShelterNames() {
        return shelterManager.getAllShelterNames();
    }

    public String generateShelterCSV(String shelterName) {
        return shelterManager.generateShelterCSV(shelterName);
    }

    public double getShelterFillPercentage(String shelterName) {
        return shelterManager.getShelterFillPercentage(shelterName);
    }

    public void addRating(String shelterName, int rating) {
        shelterManager.addRating(shelterName, rating);
    }
}
