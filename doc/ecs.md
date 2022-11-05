# Entity Component System

## Entities
### Definition:
A conglomerate of components is called an entity. They're identified by their archetype bitset/signature (what components is it made of: read archetypes) and an ID equal to the position of every of its components in their respectives buffers.

## Archetypes
### Definition:

A struct composed by a primary buffer, where pointers to secondary buffers (where components are) are stored, and a bitset type describing the "signature" of that archetype: what components is it made of. A set bit represents the presence of a component, which type corresponds with the set bit's position in the integer. This relationship will be established in an enum that enumerates all component types by a power of 2.