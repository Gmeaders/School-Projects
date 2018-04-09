/* Greg Meaders
   9/18/14
   Homework 1
   cpsc212
   Main.cpp
*/
#include <iostream>
#include <string.h>
#include <assert.h>
#include <fstream>
#include "stringset.h"

using namespace std;

int main(void)
{
    int count = 0;
    ifstream fin;
    string s;
    Stringset set;
    Stringset *reverse = new Stringset();
    
    //See how many New pages are in the file so we can set array to that size.
    fin.open("webpages.txt");
    while(fin >> s)
    { 
        if(s == "NEWPAGE") 
            count++; 
    } 
     fin.close();
     
     //creating the array of linked lists and filling it with NULL
     Page **google= new Page*[count];
     for (int i = 0; i < count; i++)
     {
        google[i] = NULL;
     }
    
     ifstream input;
     int counter = -1;
     int reverse_count = 0;
     
     //Loops through the array and fills with content for webpages
     input.open("webpages.txt");
     while(input >> s)
     {
        //Checks if its a new page, sets the next word to the url and sets the original links_to and weight
        if(s == "NEWPAGE")
        {
            counter ++;
            input >> s;
            google[counter] = new Page(s);
            google[counter]->links_to = 0;
            google[counter]->weight = 1.0/count;
            
            //setting the hash
            set.insert(google[counter]->url, counter);
        }
        //Checks if the next 7 letters in the next word are http://, if so it will be set to hyperlink, if not it goes into words
        else if(s.compare(0, 7, "http://"))
        {
            google[counter]->words = new Node(s, -1, google[counter]->words);
            if (reverse->insert(s, -1) == true)
                reverse_count++;
        }
            
        else
        { 
            google[counter]->hyperlink = new Node(s, -1, google[counter]->hyperlink);
            google[counter]->links_to++;
        }
      }
      input.close();
      
      for (int j = 0; j<50; j++)
      {
        for (int i=0; i<count; i++) 
        {
            google[i]->new_weight = 0.1/count;
        }     
        for(int i=0; i<count; i++)
        {
            for(Node *curr = google[i]->hyperlink; curr != NULL; curr = curr->next)
             {  
                int test = set.find(curr->key);
                //calculate the new pageweight
                if(curr->ID == -1) curr->ID = set.find(curr->key);
                if(test != -2) 
                google[test]->new_weight += 0.9 * (google[i]->weight / google[i]->links_to);
         }
        }
        for(int i=0; i<count; i++)
        {
            google[i]->weight = google[i]->new_weight;
        }
        }
        
        //creating the inverted index
        Node **inverted_index = new Node*[reverse_count];
        for (int i = 0; i < reverse_count; i++)
        {
            inverted_index[i] = NULL;
        }
        
        int rev_i = 0;
        delete reverse;
        reverse = new Stringset();
        
        //looping through the webpages to set up the inverted index
        for(int i=0; i<count; i++)
        {
            for(Node *curr = google[i]->words; curr != NULL; curr = curr->next)
            {
                if(reverse->insert(curr->key, rev_i) == true)
                {
                    inverted_index[rev_i] = new Node(curr->key, i, inverted_index[rev_i]);
                    rev_i++;
                }
                else
                {
                    int id;
                    id = reverse->find(curr->key);
                    inverted_index[id] = new Node(curr->key, i, inverted_index[id]);
                }
             }
          }
         
         //Loop to get input from the user, then ask them if they want to search another word 
         int go = 1;
         while(go != 0)
         {
            cout << "Enter a word" << endl;
            int check = 0;
            string input_word;
            
            //checks if the word shows up in the web pages, if not prompts to input a new word
            while(check == 0)
            { 
                cin >> input_word;
         
                if(reverse->find(input_word) == -2)
                {
                    cout << "Word not found, enter new word" << endl;
                }
                else 
                    check++;         
            }  
            //for loop to print out everything found for that word and makes the weight a more reasonable number
            for(Node *curr = inverted_index[reverse->find(input_word)]; curr != NULL; curr = curr->next)
            {
                Page *current = google[curr->ID];
                cout << (int)(current->weight * 10000000) << " " << current->url << endl;  
            }
            
            cout << "Press 0 to exit or any other number to continue ";
            cin >> go;
          }     
}
     
     
     
     
