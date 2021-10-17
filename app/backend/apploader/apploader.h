#pragma once

#include "../types.h"
#include "client.h"
#include "util/refcounter.h"

typedef struct apploader_task_t apploader_task_t;

typedef enum apploader_status_t {
    APPLOADER_STATUS_IDLE,
    APPLOADER_STATUS_LOADING
} apploader_status_t;

typedef struct apploader_item_t {
    APP_LIST base;
    bool bookmarked;
} apploader_item_t;

typedef struct apploader_t {
    const SERVER_LIST *node;
    apploader_status_t status;
    int code;
    apploader_item_t *apps;
    int apps_count;
    apploader_task_t *task;
    refcounter_t refcounter;
} apploader_t;

typedef void (*apploader_cb)(apploader_t *loader, void *userdata);

apploader_t *apploader_new(const SERVER_LIST *node);

void apploader_load(apploader_t *loader, apploader_cb cb, void *userdata);

void apploader_unref(apploader_t *loader);