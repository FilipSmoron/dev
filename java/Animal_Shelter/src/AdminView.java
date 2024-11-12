import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class AdminView extends JFrame {
    private final ShelterManager shelterManager;
    private JComboBox<String> shelterComboBox;
    private JTextArea animalsTextArea;
    private JTextField filterTextBox;
    private JComboBox<String> stateComboBox;
    private JButton sortSheltersButton;

    public AdminView(ShelterManager shelterManager) {
        this.shelterManager = shelterManager;
        setTitle("Admin Panel");
        setSize(700, 500);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

        JPanel panel = new JPanel(new BorderLayout());

        JPanel controlPanel = new JPanel(new GridLayout(0, 1));

        shelterComboBox = new JComboBox<>();
        updateShelterComboBox();

        shelterComboBox.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                showAnimalsInShelter();
            }
        });

        animalsTextArea = new JTextArea(10, 40);
        animalsTextArea.setEditable(false);

        sortSheltersButton = new JButton("Sort Shelters");
        sortSheltersButton.addActionListener(e -> sortShelters());

        filterTextBox = new JTextField("Filter by name or species...");
        filterTextBox.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                if (e.getKeyCode() == KeyEvent.VK_ENTER) {
                    filterAnimalsOrShelters();
                }
            }
        });

        stateComboBox = new JComboBox<>(new String[]{"ALL", "HEALTHY", "SICK", "IN_ADOPTION", "QUARANTINE"});
        stateComboBox.addActionListener(e -> filterByState());

        JButton addShelterButton = new JButton("Add Shelter");
        JButton addAnimalButton = new JButton("Add Animal");
        JButton removeShelterButton = new JButton("Remove Shelter");

        addShelterButton.addActionListener(e -> {
            String shelterName = JOptionPane.showInputDialog("Enter shelter name:");
            int capacity = Integer.parseInt(JOptionPane.showInputDialog("Enter max capacity:"));
            shelterManager.addShelter(shelterName, capacity);
            updateShelterComboBox();
            JOptionPane.showMessageDialog(null, "Shelter added.");
        });

        addAnimalButton.addActionListener(e -> {
            String shelterName = (String) shelterComboBox.getSelectedItem();
            if (shelterName == null) {
                JOptionPane.showMessageDialog(null, "Please select a shelter first.");
                return;
            }

            AnimalShelter shelter = shelterManager.getShelters().get(shelterName);
            if (shelter != null) {
                try {
                    String name = JOptionPane.showInputDialog("Enter animal name:");
                    String species = JOptionPane.showInputDialog("Enter animal species:");
                    String conditionInput = JOptionPane.showInputDialog("Enter animal condition (HEALTHY, SICK, IN_ADOPTION, QUARANTINE):");
                    AnimalCondition condition = AnimalCondition.valueOf(conditionInput.toUpperCase());
                    int age = Integer.parseInt(JOptionPane.showInputDialog("Enter animal age:"));
                    double price = Double.parseDouble(JOptionPane.showInputDialog("Enter animal price:"));

                    // Sprawdzanie poprawności danych
                    if (age < 0 || price < 0) {
                        throw new InvalidAnimalDataException("Age and price cannot be negative.");
                    }

                    Animal animal = new Animal(name, species, condition, age, price);
                    if (shelter.getAnimals().size() >= shelter.getMaxCapacity()) {
                        throw new ShelterCapacityExceededException("Shelter has reached its maximum capacity.");
                    }

                    shelter.addAnimal(animal);
                    showAnimalsInShelter();
                    JOptionPane.showMessageDialog(null, "Animal added.");
                } catch (InvalidAnimalDataException | ShelterCapacityExceededException ex) {
                    JOptionPane.showMessageDialog(null, ex.getMessage());
                } catch (Exception ex) {
                    JOptionPane.showMessageDialog(null, "Error adding animal: " + ex.getMessage());
                }
            } else {
                JOptionPane.showMessageDialog(null, "Shelter not found.");
            }
        });

        removeShelterButton.addActionListener(e -> {
            String shelterName = (String) shelterComboBox.getSelectedItem();
            if (shelterName != null) {
                shelterManager.removeShelter(shelterName);
                updateShelterComboBox();
                animalsTextArea.setText("");
                JOptionPane.showMessageDialog(null, "Shelter removed.");
            } else {
                JOptionPane.showMessageDialog(null, "Please select a shelter to remove.");
            }
        });

        controlPanel.add(shelterComboBox);
        controlPanel.add(sortSheltersButton);
        controlPanel.add(filterTextBox);
        controlPanel.add(stateComboBox);
        controlPanel.add(addShelterButton);
        controlPanel.add(addAnimalButton);
        controlPanel.add(removeShelterButton);

        panel.add(controlPanel, BorderLayout.NORTH);
        panel.add(new JScrollPane(animalsTextArea), BorderLayout.CENTER);

        add(panel);
    }

    private void updateShelterComboBox() {
        // Usuwamy wszystkie obecne elementy z ComboBox
        shelterComboBox.removeAllItems();

        // Dodajemy schroniska
        for (String shelterName : shelterManager.getShelters().keySet()) {
            shelterComboBox.addItem(shelterName);
        }
    }

    private void showAnimalsInShelter() {
        String selectedShelterName = (String) shelterComboBox.getSelectedItem();
        if (selectedShelterName != null) {
            AnimalShelter shelter = shelterManager.getShelters().get(selectedShelterName);
            if (shelter != null) {
                List<Animal> animals = shelter.getAnimals();
                StringBuilder animalsText = new StringBuilder("Animals in " + selectedShelterName + ":\n");
                for (Animal animal : animals) {
                    animalsText.append(animal.toString()).append("\n");
                }
                animalsTextArea.setText(animalsText.toString());
            }
        }
    }

    private void sortShelters() {
        // Pobierz posortowaną listę schronisk
        List<AnimalShelter> sortedShelters = shelterManager.getSortedShelters();

        // Aktualizujemy widok w ComboBoxie
        updateShelterComboBox(sortedShelters);

        JOptionPane.showMessageDialog(null, "Shelters sorted by max capacity.");
    }

    private void updateShelterComboBox(List<AnimalShelter> sortedShelters) {
        // Usuwamy wszystkie obecne elementy z ComboBox
        shelterComboBox.removeAllItems();

        // Dodajemy posortowane schroniska
        for (AnimalShelter shelter : sortedShelters) {
            shelterComboBox.addItem(shelter.getShelterName());
        }

        // Ustawiamy domyślnie wybrane pierwsze schronisko (po sortowaniu)
        if (!sortedShelters.isEmpty()) {
            shelterComboBox.setSelectedIndex(0); // Wybierz pierwsze schronisko
            showAnimalsInShelter();  // Wyświetl zwierzęta w wybranym schronisku
        }
    }

    private void filterAnimalsOrShelters() {
        String query = filterTextBox.getText().trim();
        if (query.isEmpty()) {
            showAnimalsInShelter();
            return;
        }

        String selectedShelterName = (String) shelterComboBox.getSelectedItem();
        if (selectedShelterName != null) {
            AnimalShelter shelter = shelterManager.getShelters().get(selectedShelterName);
            if (shelter != null) {
                List<Animal> filteredAnimals = shelter.searchPartial(query);
                StringBuilder animalsText = new StringBuilder("Filtered animals in " + selectedShelterName + ":\n");
                for (Animal animal : filteredAnimals) {
                    animalsText.append(animal.toString()).append("\n");
                }
                animalsTextArea.setText(animalsText.toString());
            }
        }
    }

    private void filterByState() {
        String selectedShelterName = (String) shelterComboBox.getSelectedItem();
        if (selectedShelterName != null) {
            AnimalShelter shelter = shelterManager.getShelters().get(selectedShelterName);
            if (shelter != null) {
                String stateFilter = (String) stateComboBox.getSelectedItem();
                List<Animal> filteredAnimals;

                if ("ALL".equals(stateFilter)) {
                    filteredAnimals = shelter.getAnimals();
                } else {
                    AnimalCondition condition = AnimalCondition.valueOf(stateFilter);
                    filteredAnimals = shelter.getAnimals().stream()
                            .filter(animal -> animal.getCondition() == condition)
                            .collect(Collectors.toList());
                }

                StringBuilder animalsText = new StringBuilder("Filtered animals by state in " + selectedShelterName + ":\n");
                for (Animal animal : filteredAnimals) {
                    animalsText.append(animal.toString()).append("\n");
                }
                animalsTextArea.setText(animalsText.toString());
            }
        }
    }
}
