//
// Created by panderium on 21/02/19.
//

#include "Truck.h"

Truck::Truck() = default;

int Truck::load(int quantity) {
    if (this->m_payload + quantity < this->m_max_payload) {
        this->m_payload += quantity;
        return 0;
    }
    return 1;
}

int Truck::unload(int quantity) {
    if (this->m_payload - quantity >= 0) {
        this->m_payload -= quantity;
        return 0;
    }
    return 1;
}

float Truck::getM_autonomy() const {
    return m_autonomy;
}

void Truck::setM_autonomy(float m_autonomy) {
    Truck::m_autonomy = m_autonomy;
}

Truck::~Truck() = default;
