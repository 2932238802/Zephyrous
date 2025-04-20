# Zephyrous - 开发文档

## Component
---
- BlockComponent
    - BlockDifficulty
        1. 方块物理采集的难易
        2. 方块存放背包的体积

    - BlockKind
        1. 泥土
        2. 石块
        3. 空

    - BlockPosition
        1. 位置

    - BlockSquare
        1. 方块面积
---

- ChunkComponent
    - ChunkConfig
        1. BlockComponent 的所有配置信息

    - ChunkIsdirty

    - ChunkIsload
        1. 是不是被加载过

    - ChunkPos
        1. 区块位置

- ComComponent
    - ComCollision
        1. 是不是碰撞

    - ComStata
        1. 是不是运动的

- PlayerComponent
    - Player
        1. 玩家所有信息

    - PlayerAcceleration
        1. 玩家加速度

    - PlayerChunk
        1. 方块

    - PlayerEquip
        1.玩家装备

    - PlayerFront
        1.玩家前刺视野

    - PlayerItem
        1.玩家物品

    - PlayerMovement
        1.玩家移动

    - PlayerPosition
        1.玩家位置

    - PlayerSpeed
        1.玩家速度

    - PlayerState
        1.玩家状态

    - PlayerVisitor
        1.鼠标检测器

- ViewComponent 
    - ViewConfig
    - ViewMove
    - ViewRuntime

- WindowComponent
    - WindowConfig
    - WindowConfigBuilder
    - WindowFactory
    - WindowRuntime
    - WindowVisitor

- Tool
    - Debug
    - Scale

## System
- ChunkSystem
- CollisionDetectionSystem
- DispatcherSystem
- MoveSystem
- PhysicsSystem
- PlayerSystem
- PlayerVisitorSystem
- RenderSystem
- System
- ViewSystem
- WindowManageSystem
- WindowVisitorSystem