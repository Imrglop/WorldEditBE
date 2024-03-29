# WorldEditBE
A Minecraft: Windows 10 Edition mod for building in local worlds.

Inspired by [WorldEdit (EngineHub)](https://enginehub.org/worldedit/)

## Features

WorldEditBE has the following features:
### Commands
- cut
- replace
- set
- sphere
- up
- walls

### Misc

- Right click Blaze Rod on a block to teleport to it (local worlds only)

## Usage

Load WorldEditBE.dll into the game using any dll loader. Join a local world. You will be able to use the chat commands. The prefix is: `-`

*Tip: To get a list of commands, run `-help`*

To set position 1 and position 2, get a wand. To set position 1, destroy a block. Right click a block to set position 2.

*Tip: To remove the mod from the game, run the `-eject` command*

## Block Patterns

A block pattern is a list of blocks. This is needed in most of the world editing commands. For example, `-set`:

To set an area with 1/3 grass, 1/3 stone, and 1/3 dirt, do:

```
-set grass,stone,dirt
```

It will be a random selection.

You can also just set a single block:

```
-set grass
```

For `-replace`, you enter 2 block patterns:

```
-replace grass,dirt stone,stonebrick
```

It will be a grid pattern of stone and stone bricks. If you add more blocks to the entries, it will become random.