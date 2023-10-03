#pragma once

#include "GalleryInterface.h"

class DateTimeInterface: public GalleryInterface {
    Q_OBJECT

public:
    explicit DateTimeInterface(QWidget* parent = nullptr);
};