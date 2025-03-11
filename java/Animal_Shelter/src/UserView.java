import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.List;

public class UserView extends JFrame {
    private final ShelterManager shelterManager; // Przechowuje instancję ShelterManager
    private JTextArea shelterInfoTextArea;      // Obszar tekstowy do wyświetlania schronisk i zwierząt

    public UserView(ShelterManager shelterManager) {
        this.shelterManager = shelterManager; // Przypisanie instancji ShelterManager
        setTitle("User Panel");
        setSize(700, 500);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

        JPanel panel = new JPanel(new BorderLayout());
        JPanel buttonPanel = new JPanel();

        JButton adoptButton = new JButton("Adopt Animal");

        // Akcja dla przycisku "Adopt Animal"
        adoptButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String shelterName = JOptionPane.showInputDialog("Enter shelter name to adopt from:");
                AnimalShelter shelter = shelterManager.getShelters().get(shelterName);

                if (shelter == null) {
                    JOptionPane.showMessageDialog(null, "Shelter not found.");
                    return;
                }

                String animalName = JOptionPane.showInputDialog("Enter animal name to adopt:");
                Animal animalToAdopt = shelter.search(animalName).stream().findFirst().orElse(null);

                if (animalToAdopt == null) {
                    JOptionPane.showMessageDialog(null, "Animal not found.");
                    return;
                }

                shelter.adoptAnimal(animalToAdopt); // Poprawne wywołanie metody adopcji
                JOptionPane.showMessageDialog(null, animalToAdopt.getName() + " has been adopted.");

                // Po adopcji aktualizujemy widok
                displaySheltersAndAnimals();
            }
        });

        // Obszar tekstowy do wyświetlania schronisk i ich zwierząt
        shelterInfoTextArea = new JTextArea(15, 50);
        shelterInfoTextArea.setEditable(false);

        // Inicjalne wyświetlenie schronisk i zwierząt
        displaySheltersAndAnimals();

        // Panel przycisków
        buttonPanel.add(adoptButton);

        // Główna struktura panelu
        panel.add(buttonPanel, BorderLayout.NORTH);
        panel.add(new JScrollPane(shelterInfoTextArea), BorderLayout.CENTER);

        add(panel);
    }

    // Metoda wyświetlająca listę schronisk i ich zwierząt
    private void displaySheltersAndAnimals() {
        StringBuilder shelterInfo = new StringBuilder();

        for (String shelterName : shelterManager.getShelters().keySet()) {
            AnimalShelter shelter = shelterManager.getShelters().get(shelterName);
            shelterInfo.append("Shelter: ").append(shelterName)
                    .append(" (Capacity: ").append(shelter.getAnimals().size())
                    .append("/").append(shelter.getMaxCapacity()).append(")\n");

            for (Animal animal : shelter.getAnimals()) {
                shelterInfo.append("  - ").append(animal.toString()).append("\n");
            }

            shelterInfo.append("\n"); // Dodatkowy odstęp między schroniskami
        }

        shelterInfoTextArea.setText(shelterInfo.toString());
    }
}
