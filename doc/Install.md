# Zephyrous - �����ĵ�

## Component
---
- BlockComponent
    - BlockDifficulty
        1. ��������ɼ�������
        2. �����ű��������

    - BlockKind
        1. ����
        2. ʯ��
        3. ��

    - BlockPosition
        1. λ��

    - BlockSquare
        1. �������
---

- ChunkComponent
    - ChunkConfig
        1. BlockComponent ������������Ϣ

    - ChunkIsdirty

    - ChunkIsload
        1. �ǲ��Ǳ����ع�

    - ChunkPos
        1. ����λ��

- ComComponent
    - ComCollision
        1. �ǲ�����ײ

    - ComStata
        1. �ǲ����˶���

- PlayerComponent
    - Player
        1. ���������Ϣ

    - PlayerAcceleration
        1. ��Ҽ��ٶ�

    - PlayerChunk
        1. ����

    - PlayerEquip
        1.���װ��

    - PlayerFront
        1.���ǰ����Ұ

    - PlayerItem
        1.�����Ʒ

    - PlayerMovement
        1.����ƶ�

    - PlayerPosition
        1.���λ��

    - PlayerSpeed
        1.����ٶ�

    - PlayerState
        1.���״̬

    - PlayerVisitor
        1.�������

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