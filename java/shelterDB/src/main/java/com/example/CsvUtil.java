package com.example;

import java.io.*;
import java.util.List;

public class CsvUtil {
    public static void exportToCsv(List<?> objects, String fileName) throws IOException {
        try (PrintWriter pw = new PrintWriter(new FileWriter(fileName))) {
            for (Object obj : objects) {
                pw.println(obj.toString());
            }
        }
    }
}
