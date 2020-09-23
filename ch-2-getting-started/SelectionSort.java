// 9/22/2020 9:38:48 PM
public class SelectionSort
{
	public static void SelectionSort(int arr[])
	{
		int how_many = 0;
		for (int i = 0, n = arr.length; i < n - 1; i++)
		{
			int j = i + 1;
			int min = arr[j];
			int index = j;
			for ( ; j < n; j++)
			{
				if (arr[j] < min)
				{
					min = arr[j];
					index = j;
				}
				how_many++;
			}
			if (arr[index] < arr[i])
			{
				int tmp = arr[i]; arr[i] = arr[index]; arr[index] = tmp;
			}
		}
		System.out.println(how_many);
	}

	public static void main(String args[])
	{
		int arr[] = {
			20, 19, 18, 17, 16, 15, 14, 13, 12, 11,
			30, 29, 28, 27, 26, 25, 24, 23, 22, 21,
			10, 9, 8, 7, 6, 5, 4, 3, 2, 1
		};
		
		// print the array unsorted
		int n = arr.length;
		for (int i = 0; i < n; i++)
			System.out.print(arr[i] + " ");
		System.out.println();
		// sort
		SelectionSort(arr);
		// print the array sorted
		for (int i = 0; i < n; i++)
			System.out.print(arr[i] + " ");
		System.out.println();
	}
}

