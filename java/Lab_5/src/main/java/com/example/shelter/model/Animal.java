package com.example.shelter.model;

import jakarta.persistence.*;
import lombok.Getter;

@Entity
public class Animal {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
    @Getter
    private String name;
    private String species;
    private int age;
    @ManyToOne
    @JoinColumn(name = "shelter_id")
    private Shelter shelter;

    // Gettery i settery
    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSpecies() {
        return species;
    }

    public void setSpecies(String species) {
        this.species = species;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public void setShelter(Shelter targetShelter) {
        this.shelter = targetShelter;
    }
}
