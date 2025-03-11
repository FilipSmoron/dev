package com.example.shelter;

import com.example.shelter.model.Animal;
import com.example.shelter.model.Shelter;
import com.example.shelter.repository.AnimalRepository;
import com.example.shelter.service.ShelterService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.stereotype.Component;

@Component
public class DataInitializer implements CommandLineRunner {
    private final ShelterService shelterService;
    private final AnimalRepository animalRepository;

    @Autowired
    public DataInitializer(ShelterService shelterService, AnimalRepository animalRepository) {
        this.shelterService = shelterService;
        this.animalRepository = animalRepository;
    }

    @Override
    public void run(String... args) {
        // Inicjalizacja przykładowych danych
        Shelter shelter = new Shelter();
        shelter.setName("City Shelter");
        shelter.setLocation("New York");
        shelter.setCapacity(10);
        shelterService.addShelter(shelter);

        Animal animal1 = new Animal();
        animal1.setName("Rex");
        animal1.setSpecies("Dog");
        animal1.setAge(5);
        animal1.setShelter(shelter);
        shelterService.addAnimal(animal1);
    }
}