package com.example.controller;

import com.example.dao.AnimalDAO;
import com.example.dao.AnimalShelterDAO;
import com.example.model.Animal;
import com.example.model.AnimalShelter;

public class AnimalController {
    private final AnimalDAO animalDAO = new AnimalDAO();
    private final AnimalShelterDAO shelterDAO = new AnimalShelterDAO();

    public void addAnimal(String name, String type, int age, Long shelterId) {
        AnimalShelter shelter = shelterDAO.getById(shelterId);
        if (shelter == null) {
            throw new IllegalArgumentException("Shelter not found");
        }

        Animal animal = new Animal();
        animal.setName(name);
        animal.setType(type);
        animal.setAge(age);
        animal.setShelter(shelter);

        animalDAO.save(animal);
    }

    public void deleteAnimal(Long animalId) {
        animalDAO.getById(animalId);
    }
}
