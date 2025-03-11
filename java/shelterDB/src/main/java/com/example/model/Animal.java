package com.example.model;

import jakarta.persistence.*;


@Entity
public class Animal {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    private String name;
    private String type;
    private int age;

    @ManyToOne
    @JoinColumn(name = "shelter_id")
    private AnimalShelter shelter;

    // Gettery i settery
    public Long getId() { return id; }
    public void setId(Long id) { this.id = id; }

    public String getName() { return name; }
    public void setName(String name) { this.name = name; }

    public String getType() { return type; }
    public void setType(String type) { this.type = type; }

    public int getAge() { return age; }
    public void setAge(int age) { this.age = age; }

    public AnimalShelter getShelter() { return shelter; }
    public void setShelter(AnimalShelter shelter) { this.shelter = shelter; }
}
