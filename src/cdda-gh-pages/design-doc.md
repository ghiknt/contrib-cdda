---
layout: page
title: "CDDA Design Document"
permalink: /design-doc/
---

### About this Page

This is the Cataclysm: DDA design document.  It is meant for designer-end planning and goal unity for an open ended project.  It is not meant to be a user facing document!  In other words, **spoiler alert**.  Do not read this document if you have no intention of contributing to the project and do not want your play experience spoiled.

### Table of Contents
* [User Experience](#user-experience)
* [Gameplay](#gameplay)
* [Game Balance](./design-balance.md)
* [Story](#story)
* [Technology](./technology.md)

Cataclysm: Dark Days Ahead is a turn-based survival game set in a post-apocalyptic world.  Struggle to survive in a harsh, persistent, procedurally generated world.  Scavenge the remnants of a dead civilization for food, equipment, or, if you are lucky, a vehicle with a full tank of gas to get you the hell out of Dodge.  Fight to defeat or escape from a wide variety of powerful monstrosities, from zombies to giant insects to killer robots and things far stranger and deadlier, and against the others like yourself, that want what you have…

#### Supporting lore documents
* [Background](./lore-background.md) - provides more information on the timeline of events leading up to the Cataclysm
* [Factions](./lore-factions.md) - in-depth discussion of in-game factions and how they should affect gameplay

# User Experience

Explore, fight and survive in an expansive post-apocalyptic game world.

The core tenet of dark days ahead is if it works in reality, it works in the game.  Scavenge and craft makeshift weapons, improvise shelter, outmaneuver enemies, find, repair and drive vehicles.  Deal with monsters using your brains, melee weapons, firearms, traps, explosives, other monsters, fire, and if all else fails, a truck or two.

### User Experience Table of Contents
* [Overview](#overview)
* [Deployment](#deployment)
* [Background](#background)
* [Key Features](#key-features)
* [Depth](#depth)
* [Reward System](#reward-system)
* [Meaningfulness](#meaningfulness)
* [Collectibles, Easter Eggs & Unlockables](#collectibles)
* [World](#world)

## Overview

DDA is a turn-based survival RPG that utilizes a top-down, grid-based view.  The graphics are either character-based or use layered tiles.

DDA presents an uncompromising survival scenario to overcome, but also presents a huge variety of options for problem solving, both of which are deeply rooted in a reality-based view of the post-apocalyptic scenario.  This grounding results in sometimes unexpected inversions of gaming tropes, where storage capacity of clothing is more important than armor, or weight of highly effective gear outweighs its effectiveness.

## Deployment

DDA is built as a standalone executable for Linux, Windows, OSX, and Android.  Ports to other platforms are welcome.

The primary platform target is laptop or desktop computers, but affordances for other platforms, such as smartphones are welcome as long as they are not invasive.

## Background

DDA has two kinds of inspirations, games and game elements that it emulates, and games and game elements that it avoids.

### Games to emulate

#### Ultima, especially Ultima III and IV.

The player-guided exploration of the Ultima games was groundbreaking, as was the insight that the game doesn't have to be about defeating enemies and killing the big bad guy.

#### Fallout Series.

Surviving in a realistic setting while scavenging for resources as your dominant means of survival is the main contribution of Fallout to DDA.  Special mention to Fallout Tactics for fusing many of the concepts from Fallout and X-com games.

#### X-Com 1 and 2.

Early X-Com games made deep and punishing tactical turn based combat interspersed with long-term character building a reality.

#### Dwarf Fortress

DF is an inspiration in many ways, it takes itself seriously without *being* too serious, it doesn't suffer (much) from "chosen one syndrome", it shows that investment in game world system verisimilitude pays off once it reaches completion, and that players have a taste for punishing and deep gameplay.

### Games to avoid

#### JRPGs

Suffer from "chosen one syndrome" to a huge degree.  Limited ability to interact with the environment.  Game world is often barely deep enough to hold up if you play as expected, *any* deviation from the chosen path usually causes the player to encounter shortcomings.

#### Minecraft

Minecraft suffers from "Bang rocks together crafting" to a massive degree.  Crafting is evocative rather than literal, leading to absurdities like a wooden wood axe.

#### Dwarf Fortress

DF seems to over-invest in world building.  The progress made by the game is astounding, but the lack of pragmatism around some aspects of the game are worrying.  Additionally the lack of emphasis on UI is IMO a much greater barrier to players than the depth of the game, which is surmountable.

## Key Features

Explore a gigantic procedurally generated world.

Unique and deep focus on the complex implications of an apocalyptic scenario.

DDA uses a hybrid turn-based system.  Each action has a move cost, many of which are procedurally determined.  Once actions deplete an actor's move points, their turn ends and any other game entities act for a similar duration.  Game actors receive an allotment of move points each turn based on their stats and conditions.  All game entities, including the player character, monsters and NPCs use the same system.

The player character in DDA navigates a 3D grid resembling voxels.  Motion is predominately within the horizontal plane, but stairs, ladders, pits, and wall climbing actions can move the player or other entities vertically as well.

The player character can see other entities in a wide area around themselves, with vision mediated by both dynamic lighting and dynamic line of sight factored in.  The player is also notified when the player character can perceive noises.

The player character can attack adjacent (and sometimes nearby) enemies with melee weapons, and distant enemies with various ranged weapons.

A great deal of game progression is gated by acquisition of items.  The player can scavenge items from the procedurally generated towns and cities, as well as more exotic locations.

The player is able to supplement these scavenged goods by crafting a wide variety of items, ranging from mundane cooking to advanced chemistry.

Structures provide a valuable resource as well, which can be found and modified or constructed from scratch.

Vehicles in various states of repair litter the world, and can be driven, repaired and modified.

NPCs can form factions either independently or with the player.

Players can acquire and install bionic modules that give them abilities unheard of in unaugmented individuals.

Alternately, the player can more directly abandon their humanity and mutate into an entirely different kind of creature.

### Senses

The player character can perceive their surroundings by sight, hearing, smell and touch.

Sight is managed by dynamic field of view and lighting systems, and works over a relatively long range, ideally approaching real-world view distances.

The player receives a rich set of auditory cues from their environment, ranging from footsteps and combat noises to environmental sounds.

A normal humans sense of smell is remarkably poor, but can still alert the player to otherwise unperceived dangers.

As a last resort, a player robbed of their sense of sight might still navigate by their sense of touch.

Additionally, the player has a limited memory of the terrain they have explored.

### Combat

There are many options for causing damage in DDA, but unlike many games, DDA allows the use of a huge number of very suboptimal weapons, and most weapons have tradeoffs.

Firearms are highly effective and operate at range, but use limited ammunition, are universally uncraftable and cause significant noise to attract enemies.

Other ranged weapons like bows and crossbows trade a great deal of range and damage output for craftable ammunition and less noise when fired.

Melee weapons are often craftable and require no consumables, but have limited damage output, place the player in danger, and consume stamina rapidly when used.

Any item the player can pick up can be thrown, with wildly varying results based on player and item stats.

Unarmed combat is possible, but is even more dangerous than armed melee combat, and usually very ineffective.

### Scavenging

The player character is expected to obtain the vast majority of their possessions by scavenging items made before the cataclysm.  With the vast reduction in population, the surplus of durable goods available to each survivor is staggering.

In general, goods should be distributed in a way representative of how they would be distributed in reality, and if this negatively impacts game balance, other game aspects such as placement of enemies should be adjusted to bring things in balance rather than adjusting the placement of items.

This results in a glut of marginally useful resources, but scarcity of ideal resources.

For example cars are extraordinarily common, but robust and functional cars that are both in full working order and not surrounded by dangerous enemies are rare.

Likewise improvised melee weapons appear in vast numbers, but quality melee weapons and powerful firearms and ammunition are somewhat harder to come by.

Clothing is totally ubiquitous, but an article of clothing that improves on the player's current ensemble and fits properly is cause for celebration.

### Crafting

The player can accumulate raw materials and tools to craft a wide variety of items to supplement what they scavenge.

Skill,tool, raw material and time requirements to craft items reflect the parameters of crafting the corresponding item in reality.

This places many useful items out of reach of most survivors, in particular staples such as electronics  internal combustion engines, most firearms and gunpowder are out of reach.

### Structures

The player can also build and modify permanent structures, providing shelter from both the environment and marauding monsters.

### Vehicles

Scavenged or built, vehicles provide a trump card of sorts for the player, providing mobility, storage and shelter all at once, at the cost of significant upkeep.

Pre-cataclysm vehicles are modeled on existing real world vehicles.

The survivor can repair, modify and even build vehicles from scratch, but the quality is never the same as the original.

### Bionics

The player can acquire Compact Bionic Modules via various means and install them in their own bodies.  Once installed, these modules can provide capabilities unheard of in the unaugmented, but at the cost of pervasive tradeoffs due to side effects inflicted by the bionics.  Bionics must also be supplied with power by installing battery modules and some kind of charging module.  The most straightforward power source is a cable charging system that can rapidly refill the player's reserves as long as they arrange for an external source of power, but other modules can provide a trickle of power from various other sources.

### Mutations

Various mutagenic substances exist that can manipulate the player's own body structure, either helping or hindering the player's abilities in unpredictable ways.  Some variants of these substances can direct the progress of the mutation in a direction more or less advantageous to the player.

## Reward System

Cataclysms reward system is built around roleplay, survival and exploration.

The key concept of the game is, "what would you do in the Cataclysm?", and the game allows you to answer that question in a bewildering number of ways.

The goal of game difficulty is to start out with survival being difficult, and get steadily more difficult over time, requiring mastery of a succession of game systems in order to continue to survive and thrive.

Acquiring mastery of the game sufficient to overcome this difficulty curve is the primary form of advancement for a player.

Cataclysm also contains a vast amount of content to explore and discover, rewarding the player with a constant stream of this content, combined and re-combined over and over by procedural generation.

## Meaningfulness

The core message to Cataclysm is that we are all cogs in a massive, uncaring universe.

## World

The primary setting of the game is present-day (2019 as of the time of writing) Earth.  The current setting is New England in the United States, but that is not a core value, and there is interest in expanding the game to other regions.

Super-technology exists, but it is mostly restricted to secret lab facilities and military special forces.  See the dedicated [technology](./technology.md) page for more information on what is specifically appropriate to the setting.

That all changed during the cataclysm, a several day long event where horrors from other dimensions flooded into the world, destroying, killing and in some cases creating, rendering the world almost unrecognizable.

After the Cataclysm, the invasion ebbed, leaving humanity crippled but not completely destroyed.  Some of the invaders remain, carving out niches for themselves, but most retreated elsewhere.

The Cataclysm:DDA game world is very much modeled on the real world, with similar geography and demographics.  Balance is adjusted by placement of otherworldly or other fictional elements such as zombies and robots in addition to natural hazards.

### Locations

#### Cities

Dense urban centers present a great deal of risk, and a great deal of reward for survivors.

Zombies or other previously-human forces tend to congregate in these areas, rendering them extremely dangerous by sheer numbers if nothing else.

On the other hand, cities are where most of the resources of the previous civilization are, ready for the taking for anyone who can survive the horde.

#### Towns

Small towns represent a good risk vs reward for early game characters.  Zombies or other monsters are attracted to previous population centers, but the smaller ones will not attract very large populations.  On the other hand, the available loot is significant, but will be lacking in exotic and high-end gear such as technology, tactical clothing, and weapons.

The primary risk is attracting an entire town full of zombies by making too much noise.

Towns present ample opportunities to maneuver, break line of sight, hide, and set up ambushes, but present many opportunities for an unwary survivor to become cornered.

If a survivor can clear an area, food, water, tools, weapons and shelter are all readily available, even to a survivor with no particular survival skills.

Vehicular access to towns is ample due to the road network, and only significantly hampered by hordes of undead and the occasional abandoned or wrecked car.

#### Fields

Fields are wide open and contain sparse resources.

Threats are few and far between, but difficult to escape except by outrunning them.

Vehicles with basic off-roading capabilities can navigate fields with ease, but it requires more ability in inclement weather.

Fields are ideal building sites for shelters, but do not supply the resources for construction.

#### Hills

Hills present both opportunities and danger.  They provide both the player and enemies ample opportunity to hide, which is mostly to the player's benefit unless heavily outnumbered.

TODO: enemies specific to hills? Caves?

#### Forests

Forests present a different set of challenges for the player.  On one hand there is a huge amount of space to lose oneself in, and huge amounts of resources available for the taking if you have appropriate skills and equipment.  On the other hand forests are just as deadly to the unprepared as a city full of zombies due to exposure and starvation.

Tactically forests provide a great resource for evading pursuers by breaking line of sight by using the dense growths of trees and underbrush, but at the same time the player might be the one ambushed.

Enemies in forests are less pervasive than in towns and cities, but can still occur in dense pockets.

#### Rivers/Lakes

Without any form of water borne vehicle, rivers represent a hard barrier to player movement.  While an unencumbered player can likely swim across a river, that leaves them vulnerable once they reach the other side.

With a water-borne vehicle, the player may achieve relative safety, but at the cost of limiting their ability to access many resources.

Rivers provide a natural source of both water and some food in the form of fish, but no access to materials for crafting.

### Events of the Cataclysm

This section is to describe exactly 'what went down' in the Cataclysm, in the official Word of God sense.  As part of the design philosophy, it is important that not all events be clearly explained to players.  This is a world where exploration unlocks the story, and certain elements should be kept mysterious.  It's very unlikely that the motivations of long-zombified scientists will ever be fully made clear.

**Spoiler alert**.  This section will contain many lore spoilers for elements that are meant to be mysterious or hard to learn in game.

### Human Factions and Organizations

This section should be used to discuss both existing and deceased major factions, but it is primarily for factions forming post-cataclysm.

See [the Faction Lore document](./lore-factions.md) for deeper details and implementation ideas.

#### General Philosophy
When creating a faction in Cataclysm, consider the following:

*    All factions were part of the same overall culture only a few months ago.  We're not at a Mad Max: Fury Road stage yet, and if anyone's acting that way they're probably basing it on a major motion picture.
*    No faction should be "good".  Everyone is in this for themselves, everyone is scared, everyone's first goal is not being eaten by zombies and their second goal is making it to the next winter.  There is no time for altruism.
*    No faction should be "evil".  No one is the villain of their own story.  Raiders may not be nice, but they believe they're doing what they need to to survive in this harsh world.
*    Factions should avoid having a single "schtick".  The Free Merchants are merchants who believe in a free market, but that's by far not everything they stand for.  Think about what the average member of your faction does in their day to day life, and remember they can't spend all their time just thinking about how much they like the free market, or cannibalism, or whatever your cool initial idea was.  Expand.

#### Major Factions

See [the Faction Lore document](./lore-factions.md) for more details.

- **Free Merchants**: Based in the refugee center, a mercantile faction that is often the first group the player meets.
- **Hell's Raiders**: An aggressively Nietzschean band of would-be transhumanists that believe the strong should rule.  Connected to many, but of course not all, bandits.
- **Old Guard**: The remnants of the United States Government, attempting to reclaim ground on the mainland from their stronghold of the Second Fleet.
- **Tacoma Commune**: A Free Merchant outpost for stable food production.  
- **Hub 01**: The last stable remnant of XEDRA, a group of AI researchers led by a near-true-AI called Melchior.
- **Isherwood Farm**: 

#### Micro Factions

- **Free Merchant Beggars**: Five beggars living in or near the Free Merchants evac center, but not considered part of the Free Merchants.

### Extradimensional and Alien Forces

There are several key extradimensional factions planned or implemented in Cataclysm.

- **The Blob**, known to XEDRA scientists as XE037, is the entity responsible for the Cataclysm itself, and for zombification.  It was discovered before the Cataclysm and was the key focus of XEDRA research leading up to the zombie outbreak.
- **Triffids** are a species of intelligent plants that crossed into our world during the initial portal storms of the Cataclysm.  They perceive humans as meat, and little else, but are probably the most human-like of all the extradimensional beings.
- **Mycus** is a dispersed intelligence whose primary interest is growing and encompassing all things.  It is strongly opposed to the Blob, but shares a lot of similarities with it.
- **The Netherum** is a disorganized collection of demonic creatures.  They do not appear to have a central underlying motivation, but are generally hostile or at least not particularly friendly.
- **The Exodii** are non-hostile transhuman refugees from dimensions that have suffered the same apocalypse as this one.  They travel from world to world, surfing the tide of the apocalypse using portal technologies.  They are willing to trade knowledge, materials, and bionics with you, but they may not be as benign as they seem.
- **The Yrax** are a group of non-friendly, non-hostile hyperadvanced robots, here to study the blob.

Also of note, the **Mi-Go** are a non-extradimensional alien race from our own dimension and others, here since prior to the Cataclysm, now swooping in to gather some slaves and some research information.

See [the Faction Lore document](./lore-factions.md) for deeper details and implementation ideas.

See [the Background document](./lore-background.md) for full details on how these aliens got here.

# Gameplay

### Gameplay Table of Contents
* [Objectives](#objectives)
* [Game Stages and Timeline](#game-stages-and-timeline)

The player can interact with the game world in a huge number of ways, if there's something a survivor can do on their own in reality, they should be able to do it in the game.  The game world is a huge uncaring machine, it doesn't react to the player's existence, it's just passively hostile.  Generally speaking the player advances in capabilities by acquiring better equipment, learning things, practicing skills, and gaining allies.

## Objectives

DDA fully embraces the sandbox concept of gaming.  There are goals in DDA, and stories and missions, but the only universal goal is survival.

Short-term objectives include obtaining gear and supplies, learning things, crafting items, helping fellow survivors and exploring.

Medium-term objectives include securing supply sources, establishing a base camp or base vehicle, recruiting NPC allies, joining a faction and clearing an area of enemies.

Long-term objectives include deeply customizing your base camp and/or vehicle, securing a large surplus of supplies, founding a faction and/or making a faction self-sufficient and defeating large groups of enemies.

## Game Stages and Timeline
#### Game Stages and Timeline Table of Contents
* [Overview](#overview-1)
* ["Lone Wolf" Play Element](#lone-wolf-play-element)
* ["Faction" Play Element](#faction-play-element)

### Overview
This is an approximation, and does not describe the expected timeline from a player perspective, but rather the expected design structure.  In other words, it should not be hard-coded that a given feature is only available on a given day, but rather, game design should make access to that feature require a particular time investment making it unlikely to obtain earlier.

All these timelines are targets.  Currently most of these features are available too early.

This assumes a start date on day 45 of spring, because personally I think that should become the canonical start.

Dev/balance notes:

One of the bottom lines of it is that there needs to be a ton more stuff to do and explore, rather than the main game objective being to level up in large leaps and bounds

This playstyle depending on longer frames of time and things taking realistic periods to be built/developed may depend more heavily on things being automated such as

- fast travel options
- schedule eat/drink/sleep/stoke fire options to allow players to skip a week or two of time
- NPCs doing more of the long term crafting and projects in a more automated way.

This would allow the pace of the game to be slowed just a little, while the calendar ran faster.

### "Lone Wolf" Play Element
#### Early game

*Characterized by*: Low to no transhuman/sci fi elements.  Focus on food security and basic survival.  Development of the skills and tools that change you from a "survivor" to a "Survivor".  Little major role for factions or large groups of NPCs except as a backdrop.  Many wandering NPCs that may be hostile, but aren't part of organized groups yet.
##### Terrified and Wet Phase

first couple days to at most first week.

**Key events**:

* Find a basic safe shelter.
* Find enough food to keep you sort of alive.
* Find some clean water.
* Make a safe fire.
* Get a basic weapon and some good clothing.

**Dangers/threats**:

* The weather and elements
* Hunger and thirst
* Zombies are a mortal danger.  A single zombie is manageable but risky.  Multiple probably merit running away.
* Dormant zombies are a major factor in cities, lying around as corpses unless disturbed.

**Other Survivors/Factions**:

*    At this stage of the game, they should be very common, and pose a huge threat if hostile.
*    Factions haven't really formed strongly at this time.  (The evacuees that will become the Free Merchants are forming the basis of their governance and have started writing notes on old money to make for fair division of resources.)

**Travel/Range**:

*    Travel is almost certainly on foot, within a day's range of shelter if one has been secured.

**Special notes**:

*    Many elements of this phase, or the entire phase, might be skipped simply by starting with a particular profession or scenario.

###### New Scavenger Phase:
From mid-spring to end of spring, year 1

**Key Events**:

*    Get some armor and weaponry that deals better with zombies
*    Scavenge small settlements and their outskirts, mainly at night
*    Obtain a stockpile of food and a more serious water source, allowing you to spend a little while crafting or reading between exploration runs
*    Begin to stockpile food, books, and tools, but shouldn't have enough food supplies to be able to spend much time reading or learning

**Dangers/Threats**:

*    Special zombies should start appearing and pose a significant threat at this point
*    Individual normal zombies can probably be managed pretty safely, with a bit of caution, but more than one or two is still a big threat.
*    Dormant zombies are still much more common than active ones (although there are many active ones)
*    Food security is not a day to day concern but is still an ever-looming issue.
*    The elements are not as big a problem at this point except when extreme.

**Other Survivors/Factions**:

*    May have one NPC follower, but they are not yet very loyal.
*    At this stage of the game, they should be very common, and pose a huge threat if hostile.
*    During this phase, factions begin to form as it becomes clear that the world has basically ended.
*    Find rumors of nearby factions (e.g.  graffiti, radio signals, other survivors, computer in evac shelter)

**Travel/Range**:

*    While survivors may have a car or bike during this phase, range is still going to be restricted to "not far from home base" as they won't have fuel reserves or ways to repair their vehicles

##### Wasteland Scavenger Phase
End of spring to mid-to-late summer, year 1

**Key events**:

*    Armour can reliably protect you from one or two zombies
*    Have at least one reliable but low-power long-range weapon, with enough ammo for regular combat, and/or a good, battle-ready melee weapon.  Possibly a more powerful long-ranged weapon with rarer ammo for emergencies.
*    Food security is currently not an issue, starting to stockpile food for winter
*    Develop a pretty secure base, with little concern about small bands of zombies slipping in.  Wandering hordes are a major threat (see below)
*    Almost certainly starting a farming operation around now
*    Have a vehicle, but it's hard to repair and still pretty precious at this point
*    Able to make scavenging runs deeper into cities to get some good loot and tools, with a bit of free time to use books and things.
*    Possibly able to set up a basic electric power grid at the base.
*    Exploring Facilities is a very risky proposition at this time.

**Dangers/Threats**:

*    A lone zombie, or even two or three, pose little threat at this point unless backed up by specials.  More than that and they run the risk of swarming and overwhelming you without careful tactics.
*    Evolutions of special zombies begin to appear and are a larger threat
*    Dormant zombies begin to wake up, forming the backbone of the first wandering hordes.  The first necromancers and a few masters appear.

**Other Survivors/Factions**

*    May have a one or two followers, at least one of which is starting to build up some loyalty
*    Still a lot of other NPCs wandering dynamically around.  Aside from bandits, they are probably becoming a little more cautiously interested in fellow survivors, rather than panicked and fearful.
*    Factions have now completely formed along their main lines and begin opening trade with each other.
*    Gain trust in other factions by running missions for them regularly

**Travel/Range**

*    Likely have a vehicle, especially an easy to maintain one like a bicycle.  Welders and repair tools are at a premium if available at all, so the vehicle is fairly precious.  Range begins to extend to fill probably the entire starting overmap as the player is able to set up safe camps and things.

##### Preparation/Skilled Scavenger Phase
Mid-to-late summer to winter, year 1

**Key Events**:

*    Return of focus to food security as winter comes closer and survivor needs to work hard on stockpiling
*    Most other key resources are now well stocked - ammo, clothing, armor.  Survivor has likely managed to make some deep forays into a few towns, loot a mansion or the upper levels of a Lab.
*    Although the player isn't equipped to install CBMs or develop higher level mutagens they probably have access to the components now, and can start projects to get them on the go over the winter.  Likewise for fancier gear and equipment that isn't available readily from raids.
*    Decreasing focus on wide ranging travel in favor of developing base defenses
*    May at this point have achieved welding tools
*    Probably has electricity and a secure water supply at home base.

**Danger/Threats**:

*    Small groups of zombies are pretty easily handled.  Evolved zombies may pose a threat.
*    Wandering hordes are becoming a big risk.  Base defense from them becomes important, especially with food stockpile protection being important.  This serves to keep the player a bit more grounded at home as well, where running into a horde is more manageable.
*    More dormant zombies coming alive, but probably at least half are still dormant (gonna need cannon fodder next spring)

**Other Survivors/Factions**:

*    Have a small group of followers of varying levels of loyalty, some of whom can be left safely at the base to protect it and work on farming/crafting
*    Begin developing a relationship with some of the major factions esp.  by selling off extra scavenged stuff now that you probably have a surplus of some things
*    Reach the point where some faction missions have run far enough to earn you enmity of opposing factions.  May have to start choosing loyalties.

**Travel/Range**:

*    Possibly able to keep a fancier vehicle running now, making range quite a bit longer, but a higher risk associated if you have a stationary base due to wandering.

##### First Winter
**Key Events**:

* Traveling outside becomes onerous (slow travel through snow), cold, and dangerous (zombies and other threats not visible under snow)
* Encourage player to stay inside, building up the base, studying, and crafting

**Dangers/Threats**:

*    Wandering hordes travel less, slowed by the snow.  Masters might take their hordes into cities and forests to avoid it
*    Dormant zombies aren't visible under the snow making towns even more dangerous.
*    The winter itself is a threat with minimal electricity and no snowplows

**Other Survivors/Factions**:

*    Survivors without factions at this point die in large numbers as hordes move into the towns they've holed up in.  This is probably the biggest die-off of survivors since the cataclysm
*    Factions hunker down, trade routes close off.  Brave players able to travel in the snow might find this a very effective time to get a huge amount of faction favor by doing important jobs, at very high risk.
*    Players who haven't set up a safe enough base might choose to use their faction favor to hunker down with one of them.

**Side note**:

*    Features to automatically consume food and drink and sleep on schedule while engages in long crafting projects would be a good way to make the winter speed by and not feel tedious, while also keeping the "homestead winter" shut-in feeling.

#### Mid-Game

*Characterized by*: Player beginning to adopt transhuman elements if desired.  First serious raids to Facilities - labs, bunkers, military bases, and other 'dungeons' - become possible.  Zombies "level up", so that you're facing not so much individual monsters as nemesis-level masters and their hordes.  Other enemy factions (triffids, mycus, mi-go, others?) begin to expand as threats.

**Side note**: As this is a switch to a very different play style, it should be possible to start out in this phase with some scenarios.

#### Late-Game

*Characterized by*: Player has numerous transhuman elements and top-tier gear.  A single player can probably take on even top-shelf zombies in large numbers, if they're smart about it.  If the player has a faction or a community of their own, protecting that group is more the challenge than trying to survive themselves as they're basically a superhero.  Earth becomes a battleground, with warring factions claiming most of the overmap.

**Balance note**: at no point should a player ever be able to simply wade into a horde of zombies without fear.  Drive a tank, sure.  Man a turret, perhaps.  Walking into the crowd however should always be at least a last ditch fool's errand.  Superhero, not demigod.

**Side note**: This shouldn't be something players can start in straight-away as the challenges of late game derive from things developed in the mid-game.

### "Faction" Play Element

*	 Starts in late Early phase or later
*    Develop and protect a community either from scratch or by joining an existing faction and rising through its ranks.
*    Focuses on building, protecting, recruiting, trading, research, and diplomacy.
*    End-game: Carve out a "safe" portion of the world, or abandon this world hoping to find another that you can survive in.

# Story

The world ended.  You don't know what caused it, but suddenly everywhere was being overrun with monsters of all kinds.  Now only a tiny fraction of humanity is alive, the dead fill the cities, and worse things are stirring in the wilderness.

Civilization is gone, but maybe you can survive.  Maybe you can find others.

For more details on individual features of the story, see:
* [Background](./lore-background.md) - provides more information on the timeline of events leading up to the Cataclysm
* [Factions](./lore-factions.md) - in-depth discussion of in-game factions and how they should affect gameplay

## Style & Structure

Storytelling in CDDA should be fragmented and emergent, to simulate the idea that nobody really knows what happened.  What people know is what they experienced, which was random and chaotic.  There were no news broadcasts informing survivors that a hostile interdimensional force had decided to conquer Earth; one day, the dead started walking, and that was sure weird; while we were all getting used to that, the world broke open and creatures from nightmares moved among us eating people and smashing stuff.  It wasn't much fun, and nobody's quite sure how it happened.

Those with the best knowledge of what happened are dead.  Some of them left notes.  Those notes should be hard to get.

Information about what really went down might be made contradictory, because it's unlikely anyone has a full and clear picture of it.  Much of what is regurgitated as fact is supposition, theory, or sheer crazy ravings.


Also, everyone has PTSD.

## Background Information

**Spoiler alert**.  This section will contain many lore spoilers for elements that are meant to be mysterious or hard to learn in game.

**Summary**:

There was an arms race to develop transhumans.  In the process, the US government discovered alternate dimensions and obtained a sample called "XE-037", a mysterious black goo that was able to reanimate the dead and cause miraculous targeted phenotype mutations.  XE-037 turned out to be intelligent - vastly so - and escaped, contaminating the groundwater and causing an enormous zombie outbreak.  As this spiraled out of control, Earth became the target of a multidimensional portal attack through which the Blob, the entity of which XE-037 is just a small part, took over our world.  Simultaneously, forces from other dimensions entered opportunistically as our dimensional fabric was destabilized.  This was the Cataclysm.

Things are a bit more stable now, but nobody is left alive to appreciate that.

For a detailed explanation of how the Cataclysm came to be, see [the Background document](./lore-background.md).

### Effects of Blob Infection

Every living thing on earth is infected by the blob.  In humans, passive blob infection has a few effects.  This has some serious ramifications for gameplay and storytelling.

**Increased Healing**
Blob infection means everyone heals more quickly from basic soft tissue injuries.  It doesn't affect immune systems and doesn't have as powerful an effect on broken bones.  It also doesn't allow regeneration… Not unless you die, first.

In-game this is an explanation for rapid player healing; note that this means that rapid healing is diegetic, ie.  characters in the game world are conscious of the fact that they heal much faster than before, and may comment on it.

**Mutation**
The Blob seems to somehow store a base state for the infected creature (purifier triggers it to revert to this state and can be thought of as a 'basic human' mutagen).  That base state can be copied and imposed on the blob by crafting mutagen that has been exposed to a target organism.  The blob also responds to radiation and certain other toxic challenges by sometimes causing random mutations.

Mutagens work in part by copying a particular creature's phenotype onto the blob, then merging that phenotype with the person consuming the mutagen.  Mutagens do *not* work by modifying the underlying genetics of the organism: they are epigenetic.

**Cognition**
The blob has a potent, albeit often subtle, effect on human cognition.

In about one quarter of the population, changes are basically unnoticeable.

For about half the population, the blob causes an increase in risk-taking behaviour, ranging from mild unsafe practices all the way to people attacking hordes of zombies with a stick.

The remaining quarter see a heavy increase in aggressive, violent behaviour, often completely out of character.  The worst of these, about 1/20 of the population, become "ferals", a form of living zombie.  These ferals actually contain a much higher concentration of blob, are not seen as hostile to zombies, and mutate naturally with time just as zombies do.  Ferals still maintain a degree of human intelligence, depending on how severely affected they are… Some can remember tool use, for example.  Ferals led to a great deal of confusion over whether the reports of the dead rising were true, as feral behavior is very similar to that of zombies.

"Blob psychosis" is an out of game term for the increased violence experienced by this quarter of the population.  Nobody in game calls it that.  Strictly speaking it's not a psychosis, but that term seems to have stuck in our game discussions.

#### Blob psychosis after the Cataclysm
Over time, most affected people acclimate and return to normal.  Some remain somewhat less risk-averse than before (eg players).  Those that tended towards high violence also drift back towards normal cognition slowly, although their actions and the memory of them likely leave them changed permanently.

True ferals are permanently altered.  Like all living humans, their numbers were severely thinned during the Cataclysm; the fact that they weren't targeted by zombies is balanced by the fact that they didn't make much effort to avoid confrontation with police and military forces.

**Ferals Now**
The majority of feral humans are difficult to distinguish from zombies.  They can grasp and use simple tools like clubs and melee weapons, and will avoid dangerous obstacles, open doors, and other very simple actions largely governed by motor memory, but that's about it.  These comprise around 1% of the zombie faction.

About a third of ferals remember more complex things.  These ferals might use complex tools properly, and would understand for example how to use a gun, activate a Hack, or put on a kevlar vest.  They lack forward thinking and executive reasoning, and would be unlikely to engage in complex tactics (they might know how to arm c4, but would not think to put it onto your base wall to blast a way in) but can nevertheless be extremely dangerous.  These comprise around 0.3% of the zombie faction.

A very dangerous tenth or so of ferals maintain most of their human intelligence.  They can use any tools they would have in life, can plan tactics, and can assess your weaknesses and use salvaged materiel to exploit them… Basically anything an NPC should be able to do.  Likely they can talk as well, although probably it would be difficult for them to be too deceptive.  These comprise about 1/1000 of the zombie faction.  Over time these will probably evolve into a variant living form of zombie Masters and become another nemesis level villain for the late game.  Feral Masters would be exceedingly rare, probably 1/10,000 or less, given the low odds of an intelligent feral living long enough to evolve.

Many of the Blob Avatars sent to earth were probably the equivalent to Feral Masters among their own species.
