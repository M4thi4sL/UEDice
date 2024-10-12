# UEDice
 DiceSystem made in Unreal Engine 5.4

his repository contains the implementation of a custom DiceActor in Unreal Engine 4/5. The DiceActor is designed for use in games or simulations where dice interactions are required, featuring physics-based collisions, custom events, and sound integration.

# Features
* Physics-based dice rolling: The dice rolls and interacts with the environment using Unreal Engine's physics system.
* Collision and hit detection: The dice registers significant hits with surfaces (like a table), and can respond with sounds or events.
* Customizable dice data: The dice's appearance (mesh and material) and face labels are customizable using data assets.
* Sound on dice impact: A sound effect plays when the dice hits a surface with sufficient force.
* Events on dice state change: When the dice comes to rest, an event broadcasts the result of the roll.
* Hover and click interactions: The dice responds to cursor hover and click actions, broadcasting relevant events.

 
![DiceSystem](https://github.com/user-attachments/assets/144ccbc2-6b5c-478f-8368-e4ccf23f808b)
