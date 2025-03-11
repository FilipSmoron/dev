package com.example.model;

import jakarta.persistence.*;

import java.time.LocalDate;

@Entity
public class Rating {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    private int value;

    @ManyToOne
    @JoinColumn(name = "shelter_id")
    private AnimalShelter shelter;

    private LocalDate date;

    @Column(nullable = false)
    private String comment;

    // Gettery i settery
    public Long getId() { return id; }
    public void setId(Long id) { this.id = id; }

    public int getValue() { return value; }
    public void setValue(int value) { this.value = value; }

    public AnimalShelter getShelter() { return shelter; }
    public void setShelter(AnimalShelter shelter) { this.shelter = shelter; }

    public LocalDate getDate() { return date; }
    public void setDate(LocalDate date) { this.date = date; }

    public String getComment() { return comment; }
    public void setComment(String comment) { this.comment = comment; }
}
