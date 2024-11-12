import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.List;

public class UserView extends JFrame {
    private final ShelterManager shelterManager; // Dodajemy pole do przechowywania instancji ShelterManager

    public UserView(ShelterManager shelterManager) {
        this.shelterManager = shelterManager; // Przypisanie instancji ShelterManager
        setTitle("User Panel");
        setSize(500, 400);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

        JPanel panel = new JPanel();
        JButton viewAnimalsButton = new JButton("View Animals");
        JButton adoptButton = new JButton("Adopt Animal");

        // Akcja dla przycisku "View Animals"
        viewAnimalsButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String shelterName = JOptionPane.showInputDialog("Enter shelter name to view animals:");
                AnimalShelter shelter = shelterManager.getShelters().get(shelterName);

                if (shelter == null) {
                    JOptionPane.showMessageDialog(null, "Shelter not found.");
                    return;
                }

                List<Animal> animals = shelter.sortByName(); // Sortowanie zwierząt po nazwie
                StringBuilder animalsList = new StringBuilder("Animals in " + shelterName + ":\n");

                for (Animal animal : animals) {
                    animalsList.append(animal.toString()).append("\n");
                }

                JOptionPane.showMessageDialog(null, animalsList.toString());
            }
        });

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
            }
        });

        panel.add(viewAnimalsButton);
        panel.add(adoptButton);
        add(panel);
    }
}
