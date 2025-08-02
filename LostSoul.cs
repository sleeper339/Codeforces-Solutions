using System;
using System.Collections.Generic;
using System.Linq;

public class LostSoul {
	
	private static void Solve(Dictionary<int, int[]> indices) {
		Console.ReadLine();
		
		string[] tokens = Console.ReadLine().Split(' ');
		int[] a = new int[tokens.Length];
		for(int i = 0; i < tokens.Length; i++) a[i] = int.Parse(tokens[i]);
		
		tokens = Console.ReadLine().Split(' ');
		
		int[] b = new int[tokens.Length];
		for(int i = 0; i < tokens.Length; i++) b[i] = int.Parse(tokens[i]);
		
		for(int i = 1; i < a.Length; i += 2) {
			int temp = a[i];
			a[i] = b[i];
			b[i] = temp;
		}
		
		indices.Clear();
		
		for(int i = 0; i < a.Length; i++) {
			var c = a[i];
			
			if (!indices.ContainsKey(c)) {
				indices.Add(c, new[] {-1, -1, i});
			}
			else {
				var lastIndex = indices[c];
				
				for(int j = 0; j < 2; j++) {
					lastIndex[j] = lastIndex[j+1];
				}
				lastIndex[2] = i;
			}
			
			c = b[i];
			if (!indices.ContainsKey(c)) {
				indices.Add(c, new[] {-1, -1, i});
			}
			else {
				var lastIndex = indices[c];
				
				for(int j = 0; j < 2; j++) {
					lastIndex[j] = lastIndex[j+1];
				}
				lastIndex[2] = i;
			}
		}
		
		int maxIndex = -1;
		foreach (var i in indices) {
			int f = i.Value[0], s = i.Value[1], t = i.Value[2];
			bool valid =
				(t >= 0 && s >= 0) && ((a[t] == i.Key && b[s] == i.Key) || (b[t] == i.Key && a[s] == i.Key));
			
			if(t > s+1 || valid) {
				maxIndex = Math.Max(maxIndex, s);
			} else {
				maxIndex = Math.Max(maxIndex, f);
			}
		}
		
		Console.WriteLine(maxIndex + 1);
	}
	
	public static void Main(string[] args) {
		int n = int.Parse(Console.ReadLine());
		Dictionary<int, int[]> indices = new Dictionary<int, int[]>();
		
		foreach(var _ in Enumerable.Range(0, n)) Solve(indices);
		
	}
}