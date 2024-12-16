# CheckAppInstance
Plugin for UE4/5 project.  
This plugin makes it possible only one instance of your game can be run at the same time.  
This can be controlled with the launch argument  
-checkinst=<0/1|false/true> it's useful for testing multiplayer game on a single pc.  
Example: game.exe -checkinst=0

**C++/Blueprints functions:**
- CheckAnotherAppInstance(bool IsEnabled = true)

ProjectSettings -> Maps&Modes -> Game Instance Class: BP_GameInstance
<img src="Example.png"/>

# Install
You can install manually by extracting archive (CheckAppInstance-X.X.X...zip) from
[Releases](https://github.com/mrbindraw/CheckAppInstance/releases) to your project plugins folder  
or build example project (ExamplePrj-UEX.X-CheckAppInstance-X.X.X.zip).  
You can install it from the marketplace [CheckAppInstance](https://www.fab.com/listings/c17f1eb9-dfd8-4f41-ba30-e6c6c43d7c98)
