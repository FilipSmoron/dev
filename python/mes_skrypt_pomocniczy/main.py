import re
import csv


# Funkcja do przetwarzania pliku i wyciągania temperatur
def process_temperature_file(input_file, output_file):
    with open(input_file, 'r') as file:
        lines = file.readlines()

    # Lista na przechowanie wyników
    temperature_data = []

    # Szukamy informacji o temperaturach przy każdym kroku
    for i, line in enumerate(lines):
        if line.startswith("Min temperature"):
            # Wyciągamy minimalną temperaturę
            min_temp = float(re.search(r"Min temperature: ([\d.]+)", line).group(1))

            # Szukamy linii z maksymalną temperaturą
            max_temp_line = lines[i + 1]
            max_temp = float(re.search(r"Max temperature: ([\d.]+)", max_temp_line).group(1))

            # Dodajemy dane do listy
            temperature_data.append([min_temp, max_temp])

    # Zapis do pliku .csv
    with open(output_file, 'w', newline='') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(['Min Temperature', 'Max Temperature'])
        writer.writerows(temperature_data)


# Przykład użycia
input_file = 'wynik_test3_4pkt_temperatury.txt'  # Ścieżka do pliku .txt
output_file = '3_4.csv'  # Ścieżka do pliku .csv

process_temperature_file(input_file, output_file)
