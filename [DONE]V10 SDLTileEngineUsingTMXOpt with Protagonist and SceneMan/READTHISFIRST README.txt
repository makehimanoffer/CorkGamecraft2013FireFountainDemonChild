README:
David Ryan Tile Engine Assignment

It's recommended you read this first before delving into the code

First of all. 
Structure:
TMXReader->One Or More Layers->Tilemap->Tiles
Game for opening window and drawing to it.


Currently I've it set up for the simplistic option between
3 tilemaps. One being the desert.tmx, the second being the isometric,
and the 3rd being a tmx file I created which hold multiple layers. 

As such, the drawing of these, demonstrates that I have effectively
and efficiently parsed individual and differing tmx files for the appropriate
information, stored it and used it to display on screen. 
However the Game state management is fairly crude. 

Isometric tilemap is done by doing a check for the orientation. 
if isometric, the tiles are setup differently:
if(strcmp(mapOrientation,"isometric")==0)
	{
		whereToDraw.x=(levelx-levely)/2;
		whereToDraw.y=((levelx + levely)/2)/2;
	}



but if they're normal they are drawn normally.

if(strcmp(mapOrientation,"orthogonal")==0)
	{
		whereToDraw.x=levelx;
		whereToDraw.y=levely;
	}


As may be noted in my code I decided to hold the gids in a vector and loop through
them as if they were a 2 dimensional array as opposed to using a 2d array.
This was as I was convinced that later we would have to do something with
concurrency and wished to ensure that they were threadsafe. 

In TMXReader.cpp I went through things in the order they would occur in the tmx,
as such it is quite linear.  But, fairly clear as to what is going on. 

there is one if for if the source is an image (as in the isometric and generic multilayer tilemap)
or another for if the source is a tsx file (as in desert). These fetch the relevant information
involved in each file format. 


Some things are vital for determining the appropriate X and Y for getting the tilerect for the given tile

With Regards Improvements:
ImageManager was created with the express purpose that only one tilesheet image was loaded. This improves
performance tremendously. And works well with the Scene Management stuff, allowing for very rapid map switching at the touch of a button.
As well as this, I had issues with the screen going to black.
This no longer happens. And occured due to integers going out of scope. No longer.

Protagonist is in and moving around.

SUMMARY:
Isometric is in.
It doesn't crash.
SDL_image is used(and as such must be in your path)
I sort of use my readme as a mean of commenting. Most things are self explanatory. 
I like to let my variables describe themselves.
Advanced Visualisation Achieved in terms of the isometric map.
Would have liked to get a camera in too.  
I have a moving protagonist in.
Scenemanagement is implemented.
Map Switching and Loading is now ridiculously fast. 

