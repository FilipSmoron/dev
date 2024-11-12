import java.util.ArrayList;
import java.util.List;
import java.util.Random;

// Singleton Pattern
public class DataGenerator {

    // 1. Statyczna instancja klasy (prywatna)
    private static DataGenerator instance;

    // Przechowuje przykładowe dane
    private List<AnimalShelter> shelters;
    private Random random;

    // Prywatny konstruktor
    private DataGenerator() {
        shelters = new ArrayList<>();
        random = new Random();
        generateData();  // Wygenerowanie przykładowych danych podczas inicjalizacji
    }

    // 2. Publiczna metoda, która zwraca jedyną instancję klasy
    public static DataGenerator getInstance() {
        if (instance == null) {
            instance = new DataGenerator();
        }
        return instance;
    }

    // 3. Metoda generująca przykładowe dane
    private void generateData() {
        // Generowanie przykładowych schronisk
        for (int i = 1; i <= 5; i++) {
            String shelterName = "Shelter " + i;
            int maxCapacity = random.nextInt(20) + 10;  // Max capacity from 10 to 30
            AnimalShelter shelter = new AnimalShelter(shelterName, maxCapacity);

            // Generowanie zwierząt do schroniska
            for (int j = 1; j <= 5; j++) {
                String animalName = "Animal " + i + "-" + j;
                String species = "Species " + j;
                AnimalCondition condition = AnimalCondition.values()[random.nextInt(AnimalCondition.values().length)];
                int age = random.nextInt(10) + 1;  // Age from 1 to 10
                double price = random.nextDouble() * 1000;  // Price between 0 and 1000

                Animal animal = new Animal(animalName, species, condition, age, price);
                shelter.addAnimal(animal);
            }

            shelters.add(shelter);
        }
    }

    // 4. Metoda zwracająca listę schronisk
    public List<AnimalShelter> getShelters() {
        return shelters;
    }
}
