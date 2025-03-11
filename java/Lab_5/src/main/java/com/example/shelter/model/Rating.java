package com.example.shelter.model;

import jakarta.persistence.*;

@Entity
public class Rating {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;
    private int rating;
    @ManyToOne
    @JoinColumn(name = "shelter_id")
    private Shelter shelter;

    public Rating(Shelter shelter, Integer rating) {
        this.shelter = shelter;
        this.rating = rating;
    }

    public Rating() {

    }

    // Gettery i settery
    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public Long getShelterId() {
        return id;
    }

    public void setShelterId(Long shelterId) {
        this.id = shelterId;
    }

    public int getRating() {
        return rating;
    }

    public void setRating(int rating) {
        this.rating = rating;
    }
}
