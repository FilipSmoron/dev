import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class AnimalShelterTest {

    @Test
    public void testAddAnimal() {
        // Tworzymy nowe schronisko
        AnimalShelter shelter = new AnimalShelter("Test Shelter", 10);

        // Tworzymy nowe zwierzę
        Animal animal = new Animal("Test Animal", "Dog", AnimalCondition.HEALTHY, 3, 100);

        // Dodajemy zwierzę do schroniska
        shelter.addAnimal(animal);

        // Sprawdzamy, czy zwierzę zostało dodane do schroniska
        assertTrue(shelter.getAnimals().contains(animal), "Shelter should contain the animal");
    }

    @Test
    public void testRemoveAnimal() {
        // Tworzymy nowe schronisko
        AnimalShelter shelter = new AnimalShelter("Test Shelter", 10);

        // Tworzymy i dodajemy zwierzę
        Animal animal = new Animal("Test Animal", "Dog", AnimalCondition.HEALTHY, 3, 100);
        shelter.addAnimal(animal);

        // Usuwamy zwierzę
        shelter.removeAnimal(animal);

        // Sprawdzamy, czy zwierzę zostało usunięte ze schroniska
        assertFalse(shelter.getAnimals().contains(animal), "Shelter should not contain the animal after removal");
    }
}
