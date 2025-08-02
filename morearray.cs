using System;

public class Program {
    static void Solve() {
        Console.ReadLine(); // Skip count line

        string[] parts = Console.ReadLine().Split(' ', StringSplitOptions.RemoveEmptyEntries);
        int n = parts.Length;

        int temp = int.Parse(parts[0]);
        int count = 1;

        for (int i = 1; i < n; i++) {
            int current = int.Parse(parts[i]);
            if (current > temp + 1) {
                count++;
                temp = current;
            }
        }

        Console.WriteLine(count);
    }

    public static void Main() {
        int t = int.Parse(Console.ReadLine());
        for (int i = 0; i < t; i++)
            Solve();
    }
}