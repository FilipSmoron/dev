package com.example.animalshelterapi;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.WebMvcTest;
import org.springframework.http.MediaType;
import org.springframework.test.web.servlet.MockMvc;

import java.util.Optional;

import static org.mockito.Mockito.*;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.*;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.*;

@WebMvcTest(AnimalShelterController.class)
public class AnimalShelterControllerTest {

    @Autowired
    private MockMvc mockMvc;

    @Autowired
    private AnimalShelterController controller;

    @Autowired
    private ShelterService shelterService;

    @BeforeEach
    void setUp() {
        reset(shelterService); // Reset mock before each test
    }

    @Test
    void addAnimal_success() throws Exception {
        Animal animal = new Animal("Fido", "Dog", "Healthy", 3, 150.0);
        String shelterName = "shelter1";

        when(shelterService.addAnimalToShelter(shelterName, animal)).thenReturn(true);

        mockMvc.perform(post("/api/animal")
                        .contentType(MediaType.APPLICATION_JSON)
                        .content("{\"name\": \"Fido\", \"type\": \"Dog\", \"status\": \"Healthy\", \"age\": 3, \"weight\": 150.0}")
                        .param("shelterName", shelterName))
                .andExpect(status().isCreated())
                .andExpect(content().string("Animal added successfully."));
    }

    @Test
    void addAnimal_shelterExists() throws Exception {
        Animal animal = new Animal("Fido", "Dog", "Healthy", 3, 150.0);
        String shelterName = "shelter1";

        when(shelterService.addAnimalToShelter(shelterName, animal)).thenReturn(true); // Zmienione na true
        mockMvc.perform(post("/api/animal")
                        .contentType(MediaType.APPLICATION_JSON)
                        .content("{\"name\": \"Fido\", \"type\": \"Dog\", \"status\": \"Healthy\", \"age\": 3, \"weight\": 150.0}")
                        .param("shelterName", shelterName))
                .andExpect(status().isCreated())
                .andExpect(content().string("Animal added successfully."));
    }

    @Test
    void addAnimal_shelterNotFound() throws Exception {
        Animal animal = new Animal("Fido", "Dog", "Healthy", 3, 150.0);
        String shelterName = "nonExistentShelter";

        when(shelterService.addAnimalToShelter(shelterName, animal)).thenThrow(new IllegalArgumentException("Shelter not found."));
        mockMvc.perform(post("/api/animal")
                        .contentType(MediaType.APPLICATION_JSON)
                        .content("{\"name\": \"Fido\", \"type\": \"Dog\", \"status\": \"Healthy\", \"age\": 3, \"weight\": 150.0}")
                        .param("shelterName", shelterName))
                .andExpect(status().isNotFound())
                .andExpect(content().string("Shelter not found."));
    }

    @Test
    void getAnimal_success() throws Exception {
        String shelterName = "shelter1";
        String animalId = "Fido";
        Animal animal = new Animal("Fido", "Dog", "Healthy", 3, 150.0);

        when(shelterService.getAnimalFromShelter(shelterName, animalId)).thenReturn(Optional.of(animal));

        mockMvc.perform(get("/api/animal/" + animalId)
                        .param("shelterName", shelterName))
                .andExpect(status().isOk())
                .andExpect(jsonPath("$.name").value("Fido"))
                .andExpect(jsonPath("$.type").value("Dog"));
    }

    @Test
    void getAnimal_notFound() throws Exception {
        String shelterName = "shelter1";
        String animalId = "NonExistent";

        when(shelterService.getAnimalFromShelter(shelterName, animalId)).thenReturn(Optional.empty());

        mockMvc.perform(get("/api/animal/" + animalId)
                        .param("shelterName", shelterName))
                .andExpect(status().isNotFound());
    }

    // Add more tests following the structure above
}
