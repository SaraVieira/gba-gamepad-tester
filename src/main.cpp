#include "bn_core.h"
#include "bn_math.h"
#include "bn_keypad.h"
#include "bn_display.h"
#include "bn_sprite_ptr.h"
#include "bn_bg_palettes.h"
#include "bn_sprite_text_generator.h"
#include "bn_bgs_mosaic.h"
#include "bn_bg_palettes.h"
#include "bn_regular_bg_actions.h"
#include "bn_regular_bg_builder.h"
#include "bn_regular_bg_attributes.h"
#include "bn_sprite_text_generator.h"
#include "bn_regular_bg_animate_actions.h"
#include "bn_regular_bg_position_hbe_ptr.h"
#include "bn_regular_bg_attributes_hbe_ptr.h"

#include "fixed_32x64_sprite_font.h"

#include "bn_sprite_items_variable_8x16_font_yellow.h"

#include "common_fixed_8x8_sprite_font.h"
#include "common_fixed_8x16_sprite_font.h"
#include "common_variable_8x8_sprite_font.h"
#include "common_variable_8x16_sprite_font.h"

#include "bn_regular_bg_items_bg.h"

namespace
{
    constexpr bn::fixed text_y_inc = 14;
    constexpr bn::fixed text_y_limit = (bn::display::height() / 2) - text_y_inc;

    constexpr bn::fixed text_x_inc = 14;
    constexpr bn::fixed text_x_limit = (bn::display::width() / 2) - text_x_inc;

    void text_scene()
    {

        bn::regular_bg_ptr bg = bn::regular_bg_items::bg.create_bg(0, 0);

        bg.set_visible(true);
        bn::vector<bn::sprite_ptr, 32>
            text_sprites;
        bn::sprite_text_generator text_generator(common::variable_8x16_sprite_font);
        text_generator.set_center_alignment();
        text_generator.generate(0, -text_y_limit, "Game Pad Test", text_sprites);
        text_generator.set_left_alignment();

        const bn::fixed_t<12> START_Y = -(text_y_limit - 20);
        const bn::fixed_t<12> SELECT_Y = -(text_y_limit - 40);
        const bn::fixed_t<12> A_Y = -(text_y_limit - 60);
        const bn::fixed_t<12> B_Y = -(text_y_limit - 80);
        const bn::fixed_t<12> R_Y = -(text_y_limit - 100);
        const bn::fixed_t<12> L_Y = -(text_y_limit - 120);
        bn::sprite_palette_item original_palette_item = text_generator.palette_item();

        if (bn::keypad::start_pressed() || bn::keypad::start_held())
        {
            text_generator.set_palette_item(bn::sprite_items::variable_8x16_font_yellow.palette_item());
            text_generator.generate(-text_x_limit, START_Y, "X", text_sprites);
        }

        text_generator.set_palette_item(original_palette_item);
        text_generator.generate(-text_x_limit + 20, START_Y, "Start", text_sprites);

        if (bn::keypad::select_pressed() || bn::keypad::select_held())
        {
            text_generator.set_palette_item(bn::sprite_items::variable_8x16_font_yellow.palette_item());
            text_generator.generate(-text_x_limit, SELECT_Y, "X", text_sprites);
        }

        text_generator.set_palette_item(original_palette_item);
        text_generator.generate(-text_x_limit + 20, SELECT_Y, "Select", text_sprites);

        if (bn::keypad::a_pressed() || bn::keypad::a_held())
        {
            text_generator.set_palette_item(bn::sprite_items::variable_8x16_font_yellow.palette_item());
            text_generator.generate(-text_x_limit, A_Y, "X", text_sprites);
        }

        text_generator.set_palette_item(original_palette_item);
        text_generator.generate(-text_x_limit + 20, A_Y, "A", text_sprites);

        if (bn::keypad::b_pressed() || bn::keypad::b_held())
        {
            text_generator.set_palette_item(bn::sprite_items::variable_8x16_font_yellow.palette_item());
            text_generator.generate(-text_x_limit, B_Y, "X", text_sprites);
        }

        text_generator.set_palette_item(original_palette_item);
        text_generator.generate(-text_x_limit + 20, B_Y, "B", text_sprites);

        if (bn::keypad::l_held() || bn::keypad::l_pressed())
        {
            text_generator.set_palette_item(bn::sprite_items::variable_8x16_font_yellow.palette_item());
            text_generator.generate(-text_x_limit, L_Y, "X", text_sprites);
        }

        text_generator.set_palette_item(original_palette_item);
        text_generator.generate(-text_x_limit + 20, L_Y, "L Trigger", text_sprites);

        if (bn::keypad::r_held() || bn::keypad::r_pressed())
        {
            text_generator.set_palette_item(bn::sprite_items::variable_8x16_font_yellow.palette_item());
            text_generator.generate(-text_x_limit, R_Y, "X", text_sprites);
        }

        text_generator.set_palette_item(original_palette_item);
        text_generator.generate(-text_x_limit + 20, R_Y, "R Trigger", text_sprites);

        text_generator.set_right_alignment();

        if (bn::keypad::up_held() || bn::keypad::up_pressed())
        {
            text_generator.set_palette_item(bn::sprite_items::variable_8x16_font_yellow.palette_item());
            text_generator.generate(text_x_limit, START_Y, "X", text_sprites);
        }

        text_generator.set_palette_item(original_palette_item);
        text_generator.generate(text_x_limit - 20, START_Y, "Up", text_sprites);

        if (bn::keypad::down_held() || bn::keypad::down_pressed())
        {
            text_generator.set_palette_item(bn::sprite_items::variable_8x16_font_yellow.palette_item());
            text_generator.generate(text_x_limit, SELECT_Y, "X", text_sprites);
        }

        text_generator.set_palette_item(original_palette_item);
        text_generator.generate(text_x_limit - 20, SELECT_Y, "Down", text_sprites);

        if (bn::keypad::left_held() || bn::keypad::left_pressed())
        {
            text_generator.set_palette_item(bn::sprite_items::variable_8x16_font_yellow.palette_item());
            text_generator.generate(text_x_limit, A_Y, "X", text_sprites);
        }

        text_generator.set_palette_item(original_palette_item);
        text_generator.generate(text_x_limit - 20, A_Y, "Left", text_sprites);

        if (bn::keypad::right_held() || bn::keypad::right_pressed())
        {
            text_generator.set_palette_item(bn::sprite_items::variable_8x16_font_yellow.palette_item());
            text_generator.generate(text_x_limit, B_Y, "X", text_sprites);
        }

        text_generator.set_palette_item(original_palette_item);
        text_generator.generate(text_x_limit - 20, B_Y, "Right", text_sprites);

        bn::core::update();
    }

}

int main()
{
    bn::core::init();

    // bn::bg_palettes::set_transparent_color(bn::color(16, 16, 16));

    while (true)
    {
        text_scene();
    }
}
