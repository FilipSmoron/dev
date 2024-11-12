import org.junit.jupiter.api.Test;

import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

public class DataGeneratorTest {

    @Test
    public void testSingleton() {
        // Pobieranie instancji DataGenerator
        DataGenerator instance1 = DataGenerator.getInstance();
        DataGenerator instance2 = DataGenerator.getInstance();

        // Sprawdzenie, czy obie instancje są takie same (singleton)
        assertSame(instance1, instance2);
    }

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
    public void testDataGeneration() {
        // Pobieramy instancję generatora danych
        DataGenerator dataGenerator = DataGenerator.getInstance();

        // Pobieramy listę schronisk
        List<AnimalShelter> shelters = dataGenerator.getShelters();

        // Sprawdzamy, czy lista schronisk nie jest pusta
        assertFalse(shelters.isEmpty(), "List of shelters should not be empty");

        // Sprawdzamy, czy każde schronisko zawiera zwierzęta
        for (AnimalShelter shelter : shelters) {
            assertFalse(shelter.getAnimals().isEmpty(), "Shelter should contain animals");
        }
    }
}
