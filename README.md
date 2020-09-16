# CheckAppInstance
Plugin for UE4 project.  
This plugin make possible only one instance of your game can be run at the same time.
This plugin created mostly who don't like C++ and work only with blueprints.

# Install
1. Unzip CheckAppInstance-X.X.X-build-win64-ueX.XX.X.zip into ROOT_UE4\Engine\Plugins
2. Make Blueprint class BP_GameInstance derived from GameInstance.
3. Call on EventInit method CheckAnotherAppInstance.
4. ProjectSettings -> Maps&Modes -> Game Instance Class: BP_GameInstance

**C++/Blueprints functions:**
- CheckAnotherAppInstance(bool IsEnabled = true)

<img src="Example.png"/>




