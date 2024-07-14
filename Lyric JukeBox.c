#include <studio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 5
#define MAX_LINE_LENGTH 100

typedef struct Song {
    char artist [MAX_LINE_LENGTH];
    char title[MAX_LINE_LENGTH];
    char album[MAX_LINE_LENGTH];
    char filename[MAX_LINE_LENGTH];
} Song;

void displayMenu(Song songs[]){
    printf("** Lyric Jukebox **\n")
    printf("Track |  Artist          | Song Title          | Album\n");
    printf("--------------------------------------------------------------------\n");
    for (int i = 0; i < MAX_SONGS; i++) {
        printf("%3d | %-16s | %-25s | %-6s\n", i + 1, songs[i].artist, songs[i].title, songs[i].album);
    }
    printf("\n");
}

// Function to read song lyrics from a file
void readLyrics(char filename[]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        printf("%s", line);
        sleep(1); // Delay for 1 second
    }

    fclose(file);
}

int main() {
    // Define your songs here (replace with your actual song information)
    Song songs[MAX_SONGS] = {
        {"Queen", "Bohemian Rhapsody", "A Night at the Opera", "lyrics_bohemian_rhapsody.txt"},
        {"Imagine Dragons", "Believer", "Evolve", "lyrics_believer.txt"},
        {"ABBA", "Dancing Queen", "Arrival", "lyrics_dancing_queen.txt"},
        {"Michael Jackson", "Billie Jean", "Thriller", "lyrics_billie_jean.txt"},
        {"Elton John", "Candle in the Wind", "Goodbye Yellow Brick Road", "lyrics_candle_in_the_wind.txt"},
    };

    // Display the jukebox menu
    displayMenu(songs);

    int choice;
    printf("Enter the track number (1-%d): ", MAX_SONGS);
    if (scanf("%d", &choice) != 1  choice < 1  choice > MAX_SONGS) {
        printf("Invalid input. Please enter a valid track number.\n");
        return 1;
    }

    // Read and display the selected song lyrics
    readLyrics(songs[choice - 1].filename);

    printf("\nThanks for listening!\n");

    return 0;
}