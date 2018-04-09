#include <stdio.h>
#include "mylist.h"

int main()
{
	int i;
	int nums1[] = { 81, 39, 47, 18, 21, 10, 51, 12, 97, 60 };
	int nums2[] = { 55, 91, 74, 51, 42, 65, 63, 68, 44, 14 };

	// STEP 1 - Create the lists
	list_t *l1, *l2;
	printf("Creating new lists...\n");
	l1 = new_list();
	l2 = new_list();
	
	if (l1 == NULL || l2 == NULL)
	{
		printf("FAILED\n");
		return 1;
	}
	
	print(l1);
	print(l2);
	
	// STEP 2 - Test append_back
	printf("\nTesting append_back...\n");
	for(i = 0; i < 5; ++i)
	{
		append_back(l1, nums1[i]);
		append_back(l2, nums2[i]);
	}
	
	print(l1);
	print(l2);
	
	// STEP 3 - Test append_front
	printf("\nTesting append_front...\n");
	for(; i < 10; ++i)
	{
		append_front(l1, nums1[i]);
		append_front(l2, nums2[i]);
	}
	
	print(l1);
	print(l2);
	
	// STEP 4 - Test remove_back
	printf("\nTesting remove_back...\n");
	for (i = 0; i < 2; ++i)
	{
		printf("Removed value from list 1: %d\n", remove_back(l1));
		printf("Removed value from list 2: %d\n", remove_back(l2));
	}
	
	print(l1);
	print(l2);
	
	// STEP 5 - Test remove_front
	printf("\nTesting remove_front...\n");
	for (i = 0; i < 2; ++i)
	{
		printf("Removed value from list 1: %d\n", remove_front(l1));
		printf("Removed value from list 2: %d\n", remove_front(l2));
	}
	
	print(l1);
	print(l2);
	
	// STEP 6 - Test get_data_at
	printf("\nTesting get_data_at...\n");
	printf("4th index of list 1 is: %d\n", get_data_at(l1, 4));
	printf("4th index of list 2 is: %d\n", get_data_at(l2, 4));
	
	// STEP 7 - Test insert_at
	printf("\nTesting insert_at...\n");
	for (i = 4; i < 6; ++i)
	{
		insert_at(l1, 2, nums1[i]);
		insert_at(l2, 2, nums2[i]);
	}
	
	print(l1);
	print(l2);
	
	// STEP 8 - Test remove_at
	printf("\nTesting remove_at...\n");
	printf("Removed value from list 1: %d\n", remove_at(l1, 5));
	printf("Removed value from list 2: %d\n", remove_at(l2, 5));
	
	print(l1);
	print(l2);
	
	return 0;
}
