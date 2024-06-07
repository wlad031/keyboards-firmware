### My custom Corne keyboard configurations

Based on [QMK firmware](https://github.com/qmk/qmk_firmware).

1. Clone QMK firmware repo.
2. Make a directory under `./keyboards/crkbd/keymaps/`.
3. Link or copy `keymap.c` and `config.h` files there.
4. Link or copy `rules.mk` to `./keyboards/crkbd`.
5. Compile following QMK instructions. There is a `docker-compose.yaml` with compiler: `docker start qmk_firmware-qmk_cli-1 -i`.
