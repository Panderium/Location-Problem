//
// Created by panderium on 21/02/19.
//

#include "truck.h"

truck::truck() = default;

int truck::load(int quantity) {
    if (this->payload + quantity < this->max_payload) {
        this->payload += quantity;
        return 0;
    }
    return 1;
}

int truck::unload(int quantity) {
    if (this->payload - quantity >= 0) {
        this->payload -= quantity;
        return 0;
    }
    return 1;
}

truck::~truck() = default;
