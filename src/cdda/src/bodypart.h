#pragma once
#ifndef CATA_SRC_BODYPART_H
#define CATA_SRC_BODYPART_H

#include <array>
#include <cstddef>
#include <initializer_list>
#include <iosfwd>
#include <string>
#include <utility>
#include <vector>

#include "enums.h"
#include "flat_set.h"
#include "int_id.h"
#include "string_id.h"
#include "translations.h"

class JsonObject;
class JsonOut;
class JsonValue;
struct body_part_type;
template <typename E> struct enum_traits;

using bodypart_str_id = string_id<body_part_type>;
using bodypart_id = int_id<body_part_type>;

extern const bodypart_str_id body_part_head;
extern const bodypart_str_id body_part_eyes;
extern const bodypart_str_id body_part_mouth;
extern const bodypart_str_id body_part_torso;
extern const bodypart_str_id body_part_arm_l;
extern const bodypart_str_id body_part_arm_r;
extern const bodypart_str_id body_part_hand_l;
extern const bodypart_str_id body_part_hand_r;
extern const bodypart_str_id body_part_leg_l;
extern const bodypart_str_id body_part_foot_l;
extern const bodypart_str_id body_part_leg_r;
extern const bodypart_str_id body_part_foot_r;

// The order is important ; pldata.h has to be in the same order
enum body_part : int {
    bp_torso = 0,
    bp_head,
    bp_eyes,
    bp_mouth,
    bp_arm_l,
    bp_arm_r,
    bp_hand_l,
    bp_hand_r,
    bp_leg_l,
    bp_leg_r,
    bp_foot_l,
    bp_foot_r,
    num_bp
};

template<>
struct enum_traits<body_part> {
    static constexpr body_part last = body_part::num_bp;
};

enum class side : int {
    BOTH,
    LEFT,
    RIGHT,
    num_sides
};

template<>
struct enum_traits<side> {
    static constexpr side last = side::num_sides;
};

// Drench cache
enum water_tolerance {
    WT_IGNORED = 0,
    WT_NEUTRAL,
    WT_GOOD,
    NUM_WATER_TOLERANCE
};

/**
 * Contains all valid @ref body_part values in the order they are
 * defined in. Use this to iterate over them.
 */
constexpr std::array<body_part, 12> all_body_parts = {{
        bp_torso, bp_head, bp_eyes, bp_mouth,
        bp_arm_l, bp_arm_r, bp_hand_l, bp_hand_r,
        bp_leg_l, bp_leg_r, bp_foot_l, bp_foot_r
    }
};

struct stat_hp_mods {

    float str_mod = 3.0f;
    float dex_mod = 0.0f;
    float int_mod = 0.0f;
    float per_mod = 0.0f;

    float health_mod = 0.0f;

    bool was_loaded = false;
    void load( const JsonObject &jsobj );
    void deserialize( const JsonObject &jo );
};

struct body_part_type {
    public:
        /**
         * the different types of body parts there are.
         * this allows for the ability to group limbs or determine a limb of a certain type
         */
        enum class type {
            // this is where helmets go, and is a vital part.
            head,
            // the torso is generally the center of mass of a creature
            torso,
            // provides sight
            sensor,
            // you eat and scream with this
            mouth,
            // may manipulate objects to some degree, is a main part
            arm,
            // manipulates objects. usually is not a main part.
            hand,
            // provides motive power
            leg,
            // helps with balance. usually is not a main part
            foot,
            // may reduce fall damage
            wing,
            // may provide balance or manipulation
            tail,
            // more of a general purpose limb, such as horns.
            other,
            num_types
        };


        bodypart_str_id id;
        bool was_loaded = false;

        // Those are stored untranslated
        translation name;
        translation name_multiple;
        translation accusative;
        translation accusative_multiple;
        translation name_as_heading;
        translation name_as_heading_multiple;
        translation smash_message;
        translation hp_bar_ui_text;
        translation encumb_text;
        // Legacy "string id"
        std::string legacy_id;
        // Legacy enum "int id"
        body_part token = num_bp;
        /** Size of the body part when doing an unweighted selection. */
        float hit_size = 0.0f;
        /** Hit sizes for attackers who are smaller, equal in size, and bigger. */
        std::array<float, 3> hit_size_relative = {{ 0.0f, 0.0f, 0.0f }};
        /**
         * How hard is it to hit a given body part, assuming "owner" is hit.
         * Higher number means good hits will veer towards this part,
         * lower means this part is unlikely to be hit by inaccurate attacks.
         * Formula is `chance *= pow(hit_roll, hit_difficulty)`
         */
        float hit_difficulty = 0.0f;
        // "Parent" of this part for damage purposes - main parts are their own "parents"
        bodypart_str_id main_part;
        // "Parent" of this part for connectedness - should be next part towards head.
        // Head connects to itself.
        bodypart_str_id connected_to;
        // A part that has no opposite is its own opposite (that's pretty Zen)
        bodypart_str_id opposite_part;
        // Parts with no opposites have BOTH here
        side part_side = side::BOTH;
        body_part_type::type limb_type = body_part_type::type::num_types;

        // fine motor control
        float manipulator_score = 0.0f;
        float manipulator_max = 0.0f;

        // modifier for lifting strength
        float lifting_score = 0.0f;

        // ability to block using martial arts
        // each whole number is a block
        float blocking_score = 0.0f;
        // how well you can breathe with this part. cumulative.
        float breathing_score = 0.0f;
        // how well you can see things. affects things like throwing dispersion. cumulative
        float vision_score = 0.0f;
        // how well you can see in the dark
        float nightvision_score = 0.0f;
        // general reaction speed - dodge
        float reaction_score = 0.0f;
        float movement_speed_score = 0.0f;
        float balance_score = 0.0f;
        float swim_score = 0.0f;

        float smash_efficiency = 0.5f;

        //Morale parameters
        float hot_morale_mod = 0.0f;
        float cold_morale_mod = 0.0f;
        float stylish_bonus = 0.0f;
        int squeamish_penalty = 0;

        int fire_warmth_bonus = 0;

        int base_hp = 60;
        stat_hp_mods hp_mods;

        // if a limb is vital and at 0 hp, you die.
        bool is_vital = false;
        bool is_limb = false;

        int drench_max = 0;

        cata::flat_set<std::string> flags;
        bool has_flag( const std::string &flag ) const;

        void load( const JsonObject &jo, const std::string &src );
        void finalize();
        void check() const;

        static void load_bp( const JsonObject &jo, const std::string &src );
        static const std::vector<body_part_type> &get_all();

        // Clears all bps
        static void reset();
        // Post-load finalization
        static void finalize_all();
        // Verifies that body parts make sense
        static void check_consistency();

        int bionic_slots() const {
            return bionic_slots_;
        }
    private:
        int bionic_slots_ = 0;
};

template<>
struct enum_traits<body_part_type::type> {
    static constexpr body_part_type::type last = body_part_type::type::num_types;
};

struct layer_details {

    std::vector<int> pieces;
    int max = 0;
    int total = 0;

    void reset();
    int layer( int encumbrance );

    bool operator ==( const layer_details &rhs ) const {
        return max == rhs.max &&
               total == rhs.total &&
               pieces == rhs.pieces;
    }
};

struct encumbrance_data {
    int encumbrance = 0;
    int armor_encumbrance = 0;
    int layer_penalty = 0;

    std::array<layer_details, static_cast<size_t>( layer_level::NUM_LAYER_LEVELS )>
    layer_penalty_details;

    void layer( const layer_level level, const int encumbrance ) {
        layer_penalty += layer_penalty_details[static_cast<size_t>( level )].layer( encumbrance );
    }

    void reset() {
        *this = encumbrance_data();
    }

    bool operator ==( const encumbrance_data &rhs ) const {
        return encumbrance == rhs.encumbrance &&
               armor_encumbrance == rhs.armor_encumbrance &&
               layer_penalty == rhs.layer_penalty &&
               layer_penalty_details == rhs.layer_penalty_details;
    }
};

class bodypart
{
    private:
        bodypart_str_id id;

        int hp_cur = 0;
        int hp_max = 0;

        int wetness = 0;
        int temp_cur = 5000; // BODYTEMP_NORM = 5000
        int temp_conv = 5000;
        int frostbite_timer = 0;

        int healed_total = 0;
        int damage_bandaged = 0;
        int damage_disinfected = 0;

        encumbrance_data encumb_data; // NOLINT(cata-serialize)

        std::array<int, NUM_WATER_TOLERANCE> mut_drench; // NOLINT(cata-serialize)

        // adjust any limb "value" based on how wounded the limb is. scaled to 0-75%
        float wound_adjusted_limb_value( float val ) const;
        // Same idea as for wounds, though not all scores get this applied. Should be applied after wounds.
        float encumb_adjusted_limb_value( float val ) const;
    public:
        bodypart(): id( bodypart_str_id::NULL_ID() ), mut_drench() {}
        explicit bodypart( bodypart_str_id id ): id( id ), hp_cur( id->base_hp ), hp_max( id->base_hp ),
            mut_drench() {}

        bodypart_id get_id() const;

        void set_hp_to_max();
        bool is_at_max_hp() const;

        float get_wetness_percentage() const;

        float get_manipulator_score() const;
        float get_encumb_adjusted_manipulator_score() const;
        float get_wound_adjusted_manipulator_score() const;
        float get_manipulator_max() const;
        float get_blocking_score() const;
        float get_lifting_score() const;
        float get_breathing_score() const;
        float get_vision_score() const;
        float get_nightvision_score() const;
        float get_reaction_score() const;
        float get_movement_speed_score() const;
        float get_balance_score() const;
        float get_swim_score( double swim_skill = 0.0 ) const;

        int get_hp_cur() const;
        int get_hp_max() const;
        int get_healed_total() const;
        int get_damage_bandaged() const;
        int get_damage_disinfected() const;
        int get_drench_capacity() const;
        int get_wetness() const;
        int get_frostbite_timer() const;
        int get_temp_cur() const;
        int get_temp_conv() const;

        std::array<int, NUM_WATER_TOLERANCE> get_mut_drench() const;

        const encumbrance_data &get_encumbrance_data() const;

        void set_hp_cur( int set );
        void set_hp_max( int set );
        void set_healed_total( int set );
        void set_damage_bandaged( int set );
        void set_damage_disinfected( int set );
        void set_wetness( int set );
        void set_temp_cur( int set );
        void set_temp_conv( int set );
        void set_frostbite_timer( int set );

        void set_encumbrance_data( const encumbrance_data &set );

        void set_mut_drench( const std::pair<water_tolerance, int> &set );

        void mod_hp_cur( int mod );
        void mod_hp_max( int mod );
        void mod_healed_total( int mod );
        void mod_damage_bandaged( int mod );
        void mod_damage_disinfected( int mod );
        void mod_wetness( int mod );
        void mod_temp_cur( int mod );
        void mod_temp_conv( int mod );
        void mod_frostbite_timer( int mod );

        void serialize( JsonOut &json ) const;
        void deserialize( const JsonObject &jo );
};

class body_part_set
{
    private:

        cata::flat_set<bodypart_str_id> parts;

        explicit body_part_set( const cata::flat_set<bodypart_str_id> &other ) : parts( other ) { }

    public:
        body_part_set() = default;
        body_part_set( std::initializer_list<bodypart_str_id> bps ) {
            for( const bodypart_str_id &bp : bps ) {
                set( bp );
            }
        }
        body_part_set unify_set( const body_part_set &rhs );
        body_part_set intersect_set( const body_part_set &rhs );

        body_part_set make_intersection( const body_part_set &rhs ) const;
        body_part_set substract_set( const body_part_set &rhs );

        void fill( const std::vector<bodypart_id> &bps );

        bool test( const bodypart_str_id &bp ) const {
            return parts.count( bp ) > 0;
        }
        void set( const bodypart_str_id &bp ) {
            parts.insert( bp );
        }
        void reset( const bodypart_str_id &bp ) {
            parts.erase( bp );
        }
        bool any() const {
            return !parts.empty();
        }
        bool none() const {
            return parts.empty();
        }
        size_t count() const {
            return parts.size();
        }

        cata::flat_set<bodypart_str_id>::iterator begin() const {
            return parts.begin();
        }

        cata::flat_set<bodypart_str_id>::iterator end() const {
            return parts.end();
        }

        void clear() {
            parts.clear();
        }

        template<typename Stream>
        void serialize( Stream &s ) const {
            s.write( parts );
        }
        template<typename Value = JsonValue, std::enable_if_t<std::is_same<std::decay_t<Value>, JsonValue>::value>* = nullptr>
        void deserialize( const Value &s ) {
            s.read( parts );
        }
};

/** Returns the new id for old token */
const bodypart_str_id &convert_bp( body_part bp );

/** Returns the opposite side. */
side opposite_side( side s );

// identify the index of a body part's "other half", or itself if not
const std::array<size_t, 12> bp_aiOther = {{0, 1, 2, 3, 5, 4, 7, 6, 9, 8, 11, 10}};

/** Returns the matching name of the body_part token. */
std::string body_part_name( const bodypart_id &bp, int number = 1 );

/** Returns the matching accusative name of the body_part token, i.e. "Shrapnel hits your X".
 *  These are identical to body_part_name above in English, but not in some other languages. */
std::string body_part_name_accusative( const bodypart_id &bp, int number = 1 );

/** Returns the name of the body parts in a context where the name is used as
 * a heading or title e.g. "Left Arm". */
std::string body_part_name_as_heading( const bodypart_id &bp, int number );

/** Returns the body part text to be displayed in the HP bar */
std::string body_part_hp_bar_ui_text( const bodypart_id &bp );

/** Returns the matching encumbrance text for a given body_part token. */
std::string encumb_text( const bodypart_id &bp );

#endif // CATA_SRC_BODYPART_H
