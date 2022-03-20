
A quest manager or quest system is a part of the video game development where you control the storyline and the progression of the chracter
in your game. It can get very simple or very complex, that is why you want to know how the story and the progression of your game very clear,
so the design process of the system gets simplified and avoid overcomplicated system design.


![https://www.artstation.com/artwork/g5NDx](./docs/assets/sergeygrechanyukfinalsmaller.png)



## Writing

Before start writing, the best aproach is to set what are the main parts the storyline, then add some related secondary quests to have a 
general feeling of the game storyline.

Stories must be crafted in such a way as to seamlessly integrate different medium forms. If done right, viewers forget they’re reading text, 
listening to sound effects, looking at visuals and scrolling down all at the same time and begin to experience it as a whole.
Each form contributes a different and new piece of information and ties in naturally with the rest of elements.

![example](./docs/assets/example.png)

## Progression

The quests order and connections will define how the game progresses and evolves. 
There are diferent aproaches to develope the progression of an interactive story, we can have 


### Lineal Progression

For lineal progression stories the quests are consecutive and dont have a complex code to handle events and keep track of the progress.
Is very straight forward, one quest after another, even having secondary quest available on each point of the story, not infuencing the main progress. 

![example](./docs/assets/lineal.png)

### Dynamic Progression

Dynamic storylines are a way to make the user expirience a story from many points of views depending on their actions and choices, increasing replayability.
This type of progrssion requieres a highly defined design since it can get very complex and extensive.
This means that for example you could have two different endings depending on the actions in previous quest or just by finding hiden path in the storyline.
Also imposing many requisits to acces certain quest in the story.

![example](./docs/assets/dynamic.png)

# Design

At this point we should have decided what type of progression our game will have, leading to design our quest system.

A system basically consist in to parts, the data structure and the behaivior. The data structure is how we organize all the elements
how many elements we will have. The behaivior is how we manage this data structure and how they comunicate between them and with the rest of the project.

![example](./docs/assets/uml.png)

##  Data Structure Design

To structure our data we have to define well each component of the system and their functionality.


Important

## Behavioral Design

State is a behavioral design pattern that allows an object to change the behavior when its internal state changes. 
The pattern extracts state-related behaviors into separate state classes and forces the original object to delegate the work to an instance of these classes, instead of acting on its own.

Important


