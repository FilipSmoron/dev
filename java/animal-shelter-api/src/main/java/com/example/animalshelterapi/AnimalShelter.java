package com.example.animalshelterapi;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class AnimalShelter {
    private String name;
    private int capacity;
    private List<Animal> animals;
    private List<Integer> ratings;

    public AnimalShelter(String name, int capacity) {
        this.name = name;
        this.capacity = capacity;
        this.animals = new ArrayList<>();
        this.ratings = new ArrayList<>();
    }

    public boolean addAnimal(Animal animal) {
        if (animals.size() < capacity) {
            animals.add(animal);
            return true;
        }
        return false;
    }

    public void removeAnimal(String animalId) {
        animals.removeIf(a -> a.getName().equals(animalId));
    }

    public Optional<Animal> getAnimal(String animalId) {
        return animals.stream()
                .filter(a -> a.getName().equals(animalId))
                .findFirst();
    }

    public List<Animal> getAnimals() {
        return animals;
    }

    public String generateCSV() {
        StringBuilder csv = new StringBuilder("Name,Type,Status,Age,Weight\n");
        for (Animal animal : animals) {
            csv.append(animal.getName()).append(",")
                    .append(animal.getType()).append(",")
                    .append(animal.getStatus()).append(",")
                    .append(animal.getAge()).append(",")
                    .append(animal.getWeight()).append("\n");
        }
        return csv.toString();
    }

    public double getFillPercentage() {
        return (double) animals.size() / capacity * 100;
    }

    public void addRating(int rating) {
        ratings.add(rating);
    }

    public String getName() {
        return name;
    }
}
