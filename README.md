# UEDice
 DiceSystem made in c++ in Unreal Engine 5.4.
 The core featurse of the system are written in c++, the rest (UI, GM, PC) is currently still in BP as these would most likely be changed by the end-user to suit their needs. 

# Features
* Physics-based dice rolling. Launch dice based on the arrow in BP_DiceThrower. 
* Event-based: When the dice comes to rest, an event broadcasts the result of the roll.
* Customizable dice data: The dice's appearance (mesh and material) and face labels are customizable using data assets.
* The dice-thrower keeps track of the global total.
* Tracks invalid dice rolls, eg a coin that lands on it side, or a dice that is indetermined. 
* Hover and click interactions: The dice responds to cursor hover and click actions, clicking rerolls the dice

 

 
![DiceSystem](https://github.com/user-attachments/assets/144ccbc2-6b5c-478f-8368-e4ccf23f808b)
