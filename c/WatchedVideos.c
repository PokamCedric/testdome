/*
Implement the count_views function. It accepts an array of pointers to the Viewer struct, the size of the array, and the character array with the video name. It should return the number of Viewers who have watched a Video with the name video_name.

For example,

Video videos[] = { {.name = "Soccer", .unique_views = 500},
                   {.name = "Basketball", .unique_views = 1000} };
Viewer viewer = {.username = "Dave", .watched_videos = videos,
                 .watched_videos_size = 2};    
Viewer *viewers[] = { &viewer };

calling count_views(viewers, 1, "Soccer") should return 1.
*/

#import <stdio.h>
#import <stdlib.h>

typedef struct Video {
    char *name;
    int unique_views;
} Video;

typedef struct Viewer {
    char *username;
    Video *watched_videos;
    int watched_videos_size;
} Viewer;


int hasViewVideo(const Viewer viewer, const char *video_name){
    int hasViewed = 0;
    Video *videos = viewer.watched_videos;
    for(int index = 0; index < viewer.watched_videos_size; index++){
        if( strcmp(videos[index].name, video_name) == 0)
        {
            hasViewed = 1;
        }
    }    
    
    return hasViewed;

}

int count_views(Viewer **viewers, int viewers_size, const char *video_name)
{
    int numberOfViewers = 0;

    for(int index = 0; index < viewers_size; index++)
    {

        if(hasViewVideo(viewers[index][0], video_name)){
            numberOfViewers++;
        }
    }
    // Waiting to be implemented
    return numberOfViewers;
}
