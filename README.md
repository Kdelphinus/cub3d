# cub3d

## 1. 개요

레이캐스팅을 사용하여 게임 맵 만들기

## 2. 팀

|팀이름|구성원|할 일|
|:---|:---|:---|
|파싱|재권, 규선|맵 파싱|
|실행|단비, 명준|레이캐스팅|

## 3. 맵 규칙

- '.cub' 로 끝나야 합니다.
- 벽 이미지 파일은 xpm 확장자만 호환됩니다.
- 맵은 빈 공간이 '0', 벽은 '1'로 표현합니다.
- 주어진 지도는 벽으로 둘러 쌓여 있어야 합니다.
- 플레이어는 한 명만 있어야 하며 바라보는 방향에 따라 'N', 'S', 'W', 'E' 중 하나로 표현됩니다.

```
# 지도 예시
NO {북쪽을 바라볼 때 나오는 벽 이미지 경로}
SO {남쪽을 바라볼 때 나오는 벽 이미지 경로}
WE {서쪽을 바라볼 때 나오는 벽 이미지 경로}
EA {동쪽을 바라볼 때 나오는 벽 이미지 경로}

F {바닥색의 RGB값으로 공백없이 ','로 구분 / ex) 255,255,255}
C {천장색의 RGB값으로 공백없이 ','로 구분 / ex) 255,255,255}

지도 정보(예시는 tmp_map.cub 참고)
```

## 참고 자료

- [42seoul, cub3d](https://cdn.intra.42.fr/pdf/pdf/78383/en.subject.pdf)
- [lodev tutorial](https://lodev.org/cgtutor/)
- [lodev tutorial for korean](https://github.com/365kim/raycasting_tutorial)
