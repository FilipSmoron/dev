package com.example.shelter.controller;

import com.example.shelter.model.Animal;
import com.example.shelter.model.Rating;
import com.example.shelter.model.Shelter;
import com.example.shelter.service.ShelterService;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/api")
public class ShelterController {

    private final ShelterService shelterService;

    public ShelterController(ShelterService shelterService) {
        this.shelterService = shelterService;
    }

    // Standardowe endpointy z listy

    // 1. POST /api/animal - dodaje zwierzę do schroniska
    @PostMapping("/animal")
    public ResponseEntity<Animal> addAnimal(@RequestBody Animal animal) {
        // Walidacja danych wejściowych
        if (animal == null) {
            throw new IllegalArgumentException("Dane zwierzęcia nie mogą być puste");
        }
        if (animal.getName() == null || animal.getName().isEmpty()) {
            throw new IllegalArgumentException("Nazwa zwierzęcia jest wymagana");
        }

        Animal savedAnimal = shelterService.addAnimal(animal);
        return ResponseEntity.status(HttpStatus.CREATED).body(savedAnimal);
    }

    // 2. DELETE /api/animal/{id} - usuwa zwierzę ze schroniska
    @DeleteMapping("/animal/{id}")
    public ResponseEntity<Void> deleteAnimal(@PathVariable Long id) {
        boolean deleted = shelterService.deleteAnimal(id);
        if (deleted) {
            return ResponseEntity.noContent().build();
        }
        return ResponseEntity.notFound().build();
    }

    // 3. GET /api/animal/{id} - zwraca informacje o zwierzęciu
    @GetMapping("/animal/{id}")
    public ResponseEntity<Animal> getAnimalById(@PathVariable Long id) {
        Animal animal = shelterService.getAnimalById(id);
        if (animal != null) {
            return ResponseEntity.ok(animal);
        }
        return ResponseEntity.notFound().build();
    }

    // 4. GET /api/animalshelter/csv - zwraca informacje o schronisku w formie pliku CSV
    @GetMapping("/animalshelter/csv")
    public ResponseEntity<String> exportSheltersToCsv() {
        String csvContent = shelterService.generateSheltersCsv();
        return ResponseEntity.ok()
                .header(HttpHeaders.CONTENT_DISPOSITION, "attachment; filename=shelters.csv")
                .body(csvContent);
    }

    // 5. GET /api/sheltermanager - zwraca wszystkie schroniska
    @GetMapping("/sheltermanager")
    public ResponseEntity<List<Shelter>> getAllShelters() {
        List<Shelter> shelters = shelterService.getAllShelters();
        return ResponseEntity.ok(shelters);
    }

    // 6. POST /api/animalshelter - dodaje nowe schronisko
    @PostMapping("/animalshelter")
    public ResponseEntity<Shelter> addShelter(@RequestBody Shelter shelter) {
        Shelter savedShelter = shelterService.addShelter(shelter);
        return ResponseEntity.status(HttpStatus.CREATED).body(savedShelter);
    }

    // 7. DELETE /api/animalshelter/{id} - usuwa schronisko
    @DeleteMapping("/animalshelter/{id}")
    public ResponseEntity<Void> deleteShelter(@PathVariable Long id) {
        boolean deleted = shelterService.deleteShelter(id);
        if (deleted) {
            return ResponseEntity.noContent().build();
        }
        return ResponseEntity.notFound().build();
    }

    // 8. GET /api/animalshelter/{id}/animal - zwraca wszystkie zwierzęta w schronisku
    @GetMapping("/animalshelter/{id}/animal")
    public ResponseEntity<List<Animal>> getAnimalsInShelter(@PathVariable Long id) {
        List<Animal> animals = shelterService.getAnimalsInShelter(id);
        if (animals != null) {
            return ResponseEntity.ok(animals);
        }
        return ResponseEntity.notFound().build();
    }

    // 9. GET /api/animalshelter/{id}/fill - zwraca zapełnienie w schronisku
    @GetMapping("/animalshelter/{id}/fill")
    public ResponseEntity<Double> getShelterFillPercentage(@PathVariable Long id) {
        Double fillPercentage = shelterService.calculateShelterFillPercentage(id);
        if (fillPercentage != null) {
            return ResponseEntity.ok(fillPercentage);
        }
        return ResponseEntity.notFound().build();
    }

    // 10. POST /api/rating - dodaje ocenę dla schroniska
    @PostMapping("/rating")
    public ResponseEntity<Rating> addShelterRating(
            @RequestParam Long shelterId,
            @RequestParam Integer rating) {
        Rating savedRating = shelterService.addShelterRating(shelterId, rating);
        return ResponseEntity.status(HttpStatus.CREATED).body(savedRating);
    }

    // DODATKOWE WŁASNE ENDPOINTY

    // 11. GET /api/animal/species/{species} - zwraca zwierzęta danego gatunku
    @GetMapping("/animal/species/{species}")
    public ResponseEntity<List<Animal>> getAnimalsBySpecies(@PathVariable String species) {
        List<Animal> animals = shelterService.findAnimalsBySpecies(species);
        return ResponseEntity.ok(animals);
    }

    // 12. GET /api/animalshelter/location/{location} - zwraca schroniska w danej lokalizacji
    @GetMapping("/animalshelter/location/{location}")
    public ResponseEntity<List<Shelter>> getSheltersByLocation(@PathVariable String location) {
        List<Shelter> shelters = shelterService.findSheltersByLocation(location);
        return ResponseEntity.ok(shelters);
    }

    // 13. GET /api/rating/average/{shelterId} - pobiera średnią ocenę schroniska
    @GetMapping("/rating/average/{shelterId}")
    public ResponseEntity<Double> getShelterAverageRating(@PathVariable Long shelterId) {
        Double averageRating = shelterService.calculateShelterAverageRating(shelterId);
        if (averageRating != null) {
            return ResponseEntity.ok(averageRating);
        }
        return ResponseEntity.notFound().build();
    }

    // 14. PUT /api/animal/{id}/shelter - przenosi zwierzę do innego schroniska
    @PutMapping("/animal/{animalId}/shelter")
    public ResponseEntity<Animal> transferAnimalToShelter(
            @PathVariable Long animalId,
            @RequestParam Long targetShelterId) {
        Animal transferredAnimal = shelterService.transferAnimalToShelter(animalId, targetShelterId);
        return ResponseEntity.ok(transferredAnimal);
    }

    // 15. GET /api/animal/age/{minAge}/{maxAge} - zwraca zwierzęta w przedziale wiekowym
    @GetMapping("/animal/age/{minAge}/{maxAge}")
    public ResponseEntity<List<Animal>> getAnimalsByAgeRange(
            @PathVariable int minAge,
            @PathVariable int maxAge) {
        List<Animal> animals = shelterService.findAnimalsByAgeRange(minAge, maxAge);
        return ResponseEntity.ok(animals);
    }
}
