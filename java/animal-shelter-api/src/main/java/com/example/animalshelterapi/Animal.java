package com.example.animalshelterapi;

public class Animal {
    private String name;
    private String type;
    private String status;
    private int age;
    private double weight;

    // Konstruktor
    public Animal(String name, String type, String status, int age, double weight) {
        this.name = name;
        this.type = type;
        this.status = status;
        this.age = age;
        this.weight = weight;
    }

    // Getter
    public String getName() {
        return name;
    }

    // Setters (opcjonalne)
    public void setName(String name) {
        this.name = name;
    }

    // Dodatkowe Gettery i Settery dla pozostałych pól
    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public String getStatus() {
        return status;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public double getWeight() {
        return weight;
    }

    public void setWeight(double weight) {
        this.weight = weight;
    }
}
