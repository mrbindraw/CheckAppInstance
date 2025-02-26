# CheckAppInstance 
This plugin allows you to run only one instance of your game at the same time.  
You can enable/disable check instance from the launch argument to the game binary file  
`-checkinst=<0/1|false/true>`, this is useful for testing multiplayer game on a single pc.  
Example: `game -checkinst=0`

**C++/Blueprints functions:**
- CheckAnotherAppInstance(bool IsEnabled = true)

ProjectSettings -> Maps&Modes -> Game Instance Class: BP_GameInstance
<img src="Example.png"/>

# Install into Project
You can install manually by extracting archive `CheckAppInstance-X.X.X-UE-X.X.zip` from
[Releases](https://github.com/mrbindraw/CheckAppInstance/releases) to your project plugins folder  
or build example project `ExamplePrj-UE-X.X-CheckAppInstance-X.X.X.zip`.  

# Install into Unreal Engine  
You can install it from the marketplace [CheckAppInstance](https://www.fab.com/listings/c17f1eb9-dfd8-4f41-ba30-e6c6c43d7c98)

Manual:   
1. Download and extracting archive `CheckAppInstance-X.X.X-UE-X.X.zip` from [Releases](https://github.com/mrbindraw/ProjectVersionFromGit/releases) to any disk path, for example: `D:\Plugins`  
2. Than open any terminal (cmd, powershell) in `D:\Plugins` folder  
3. Launch `RunUAT` in the terminal with arguments, for example:

Windows:
```  
D:\EpicGames\UE_5.4\Engine\Build\BatchFiles\RunUAT.bat BuildPlugin -Plugin=D:\Plugins\CheckAppInstance\CheckAppInstance.uplugin -Package=D:\Plugins\UE_5.4\CheckAppInstance -Rocket
```
Mac:
```
sh "/Users/Shared/Epic Games/UE_5.4/Engine/Build/BatchFiles/RunUAT.sh" BuildPlugin -Plugin="$PWD/CheckAppInstance/CheckAppInstance.uplugin" -Package="$PWD/5.4/CheckAppInstance" -Rocket
```
4. If you see the message `BUILD SUCCESSFUL` in the terminal after the build is complete,  
copy the `CheckAppInstance` folder from `D:\Plugins\UE_5.4` to `D:\EpicGames\UE_5.4\Engine\Plugins\Marketplace`  
> [!IMPORTANT]
> **The engine path and folder names may differ on your system.**
