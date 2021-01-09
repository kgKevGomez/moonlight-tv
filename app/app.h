#pragma once

typedef void *APP_WINDOW_CONTEXT;

int app_init(int argc, char *argv[]);

APP_WINDOW_CONTEXT app_window_create();

void app_destroy();

void app_main_loop(void *data);