package com.example.animalshelterapi;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;
import java.util.Optional;

@RestController
@RequestMapping("/api")
public class AnimalShelterController {

    private final ShelterService shelterService;

    @Autowired
    public AnimalShelterController(ShelterService shelterService) {
        this.shelterService = shelterService;
    }

    @PostMapping("/animal")
    public ResponseEntity<String> addAnimal(@RequestBody Animal animal, @RequestParam String shelterName) {
        try {
            shelterService.addAnimalToShelter(shelterName, animal);
            return ResponseEntity.status(HttpStatus.CREATED).body("Animal added successfully.");
        } catch (IllegalArgumentException e) {
            return ResponseEntity.status(HttpStatus.NOT_FOUND).body(e.getMessage());
        }
    }

    @DeleteMapping("/animal/{id}")
    public ResponseEntity<String> removeAnimal(@PathVariable String id, @RequestParam String shelterName) {
        try {
            shelterService.removeAnimalFromShelter(shelterName, id);
            return ResponseEntity.ok("Animal removed successfully.");
        } catch (IllegalArgumentException e) {
            return ResponseEntity.status(HttpStatus.NOT_FOUND).body(e.getMessage());
        }
    }

    @GetMapping("/animal/{id}")
    public ResponseEntity<Animal> getAnimal(@PathVariable String id, @RequestParam String shelterName) {
        Optional<Animal> animal = shelterService.getAnimalFromShelter(shelterName, id);
        return animal.map(ResponseEntity::ok)
                .orElseGet(() -> ResponseEntity.status(HttpStatus.NOT_FOUND).build());
    }

    @GetMapping("/animalshelter/csv")
    public ResponseEntity<String> getShelterCSV(@RequestParam String shelterName) {
        try {
            String csv = shelterService.generateShelterCSV(shelterName);
            return ResponseEntity.ok(csv);
        } catch (IllegalArgumentException e) {
            return ResponseEntity.status(HttpStatus.NOT_FOUND).body(e.getMessage());
        }
    }

    @GetMapping("/sheltermanager")
    public ResponseEntity<List<String>> getAllShelters() {
        List<String> shelters = shelterService.getAllShelterNames();
        return ResponseEntity.ok(shelters);
    }

    @PostMapping("/animalshelter")
    public ResponseEntity<String> addShelter(@RequestParam String name, @RequestParam int capacity) {
        shelterService.addShelter(name, capacity);
        return ResponseEntity.status(HttpStatus.CREATED).body("Shelter added successfully.");
    }

    @DeleteMapping("/animalshelter/{id}")
    public ResponseEntity<String> removeShelter(@PathVariable String id) {
        try {
            shelterService.removeShelter(id);
            return ResponseEntity.ok("Shelter removed successfully.");
        } catch (IllegalArgumentException e) {
            return ResponseEntity.status(HttpStatus.NOT_FOUND).body(e.getMessage());
        }
    }

    @GetMapping("/animalshelter/{id}/animal")
    public ResponseEntity<List<Animal>> getAnimalsInShelter(@PathVariable String id) {
        List<Animal> animals = shelterService.getAnimalsInShelter(id);
        return ResponseEntity.ok(animals);
    }

    @GetMapping("/animalshelter/{id}/fill")
    public ResponseEntity<Double> getShelterFillPercentage(@PathVariable String id) {
        try {
            double fillPercentage = shelterService.getShelterFillPercentage(id);
            return ResponseEntity.ok(fillPercentage);
        } catch (IllegalArgumentException e) {
            return ResponseEntity.status(HttpStatus.NOT_FOUND).body(null);
        }
    }

    @PostMapping("/rating")
    public ResponseEntity<String> addRating(@RequestParam String shelterName, @RequestParam int rating) {
        try {
            shelterService.addRating(shelterName, rating);
            return ResponseEntity.ok("Rating added successfully.");
        } catch (IllegalArgumentException e) {
            return ResponseEntity.status(HttpStatus.NOT_FOUND).body(e.getMessage());
        }
    }
}
