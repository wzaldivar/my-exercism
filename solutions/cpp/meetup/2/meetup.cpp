#include "meetup.h"

namespace meetup {
    scheduler::scheduler(boost::gregorian::date::month_type month,
                         boost::gregorian::date::year_type year) : month(month), year(year) {
        boost::gregorian::date initial_date{year, month, 1};
        auto first_day = initial_date.day_of_week().as_number();
        for (uint8_t i = 0; i < 7; ++i) {
            this->first_week[(first_day + i) % 7] = i + 1;
        }
    }

    boost::gregorian::date scheduler::get_teenth(boost::date_time::weekdays week_day) const {
        uint8_t teenth = this->first_week[week_day];
        while (teenth < 13) {
            teenth += 7;
        }
        return {this->year, this->month, teenth};
    }

    boost::gregorian::date scheduler::monteenth() const {
        return get_teenth(boost::date_time::weekdays::Monday);
    }

    boost::gregorian::date scheduler::tuesteenth() const {
        return get_teenth(boost::date_time::weekdays::Tuesday);
    }

    boost::gregorian::date scheduler::wednesteenth() const {
        return get_teenth(boost::date_time::weekdays::Wednesday);
    }

    boost::gregorian::date scheduler::thursteenth() const {
        return get_teenth(boost::date_time::Thursday);
    }

    boost::gregorian::date scheduler::friteenth() const {
        return get_teenth(boost::date_time::Friday);
    }

    boost::gregorian::date scheduler::saturteenth() const {
        return get_teenth(boost::date_time::Saturday);
    }

    boost::gregorian::date scheduler::sunteenth() const {
        return get_teenth(boost::date_time::Sunday);
    }

    boost::gregorian::date scheduler::get_nth(boost::date_time::weekdays week_day, week_offset offset) const {
        return {this->year, this->month, first_week[week_day] + 7 * (uint8_t) offset};
    }

    boost::gregorian::date scheduler::first_monday() const {
        return get_nth(boost::date_time::Monday, week_offset::FIRST);
    }

    boost::gregorian::date scheduler::first_tuesday() const {
        return get_nth(boost::date_time::Tuesday, week_offset::FIRST);
    }

    boost::gregorian::date scheduler::first_wednesday() const {
        return get_nth(boost::date_time::Wednesday, week_offset::FIRST);
    }

    boost::gregorian::date scheduler::first_thursday() const {
        return get_nth(boost::date_time::Thursday, week_offset::FIRST);
    }

    boost::gregorian::date scheduler::first_friday() const {
        return get_nth(boost::date_time::Friday, week_offset::FIRST);
    }

    boost::gregorian::date scheduler::first_saturday() const {
        return get_nth(boost::date_time::Saturday, week_offset::FIRST);
    }

    boost::gregorian::date scheduler::first_sunday() const {
        return get_nth(boost::date_time::Sunday, week_offset::FIRST);
    }

    boost::gregorian::date scheduler::second_monday() const {
        return get_nth(boost::date_time::Monday, week_offset::SECOND);
    }

    boost::gregorian::date scheduler::second_tuesday() const {
        return get_nth(boost::date_time::Tuesday, week_offset::SECOND);
    }

    boost::gregorian::date scheduler::second_wednesday() const {
        return get_nth(boost::date_time::Wednesday, week_offset::SECOND);
    }

    boost::gregorian::date scheduler::second_thursday() const {
        return get_nth(boost::date_time::Thursday, week_offset::SECOND);
    }

    boost::gregorian::date scheduler::second_friday() const {
        return get_nth(boost::date_time::Friday, week_offset::SECOND);
    }

    boost::gregorian::date scheduler::second_saturday() const {
        return get_nth(boost::date_time::Saturday, week_offset::SECOND);
    }

    boost::gregorian::date scheduler::second_sunday() const {
        return get_nth(boost::date_time::Sunday, week_offset::SECOND);
    }

    boost::gregorian::date scheduler::third_monday() const {
        return get_nth(boost::date_time::Monday, week_offset::THIRD);
    }

    boost::gregorian::date scheduler::third_tuesday() const {
        return get_nth(boost::date_time::Tuesday, week_offset::THIRD);
    }

    boost::gregorian::date scheduler::third_wednesday() const {
        return get_nth(boost::date_time::Wednesday, week_offset::THIRD);
    }

    boost::gregorian::date scheduler::third_thursday() const {
        return get_nth(boost::date_time::Thursday, week_offset::THIRD);
    }

    boost::gregorian::date scheduler::third_friday() const {
        return get_nth(boost::date_time::Friday, week_offset::THIRD);
    }

    boost::gregorian::date scheduler::third_saturday() const {
        return get_nth(boost::date_time::Saturday, week_offset::THIRD);
    }

    boost::gregorian::date scheduler::third_sunday() const {
        return get_nth(boost::date_time::Sunday, week_offset::THIRD);
    }

    boost::gregorian::date scheduler::fourth_monday() const {
        return get_nth(boost::date_time::Monday, week_offset::FOURTH);
    }

    boost::gregorian::date scheduler::fourth_tuesday() const {
        return get_nth(boost::date_time::Tuesday, week_offset::FOURTH);
    }

    boost::gregorian::date scheduler::fourth_wednesday() const {
        return get_nth(boost::date_time::Wednesday, week_offset::FOURTH);
    }

    boost::gregorian::date scheduler::fourth_thursday() const {
        return get_nth(boost::date_time::Thursday, week_offset::FOURTH);
    }

    boost::gregorian::date scheduler::fourth_friday() const {
        return get_nth(boost::date_time::Friday, week_offset::FOURTH);
    }

    boost::gregorian::date scheduler::fourth_saturday() const {
        return get_nth(boost::date_time::Saturday, week_offset::FOURTH);
    }

    boost::gregorian::date scheduler::fourth_sunday() const {
        return get_nth(boost::date_time::Sunday, week_offset::FOURTH);
    }

    boost::gregorian::date scheduler::get_last(boost::date_time::weekdays week_day) const {
        auto last_day = boost::gregorian::date(year, month, 1).end_of_month().day().as_number();
        uint8_t last = this->first_week[week_day];
        while (last + 7 <= last_day) {
            last += 7;
        }
        return {this->year, this->month, last};
    }

    boost::gregorian::date scheduler::last_monday() const {
        return get_last(boost::date_time::Monday);
    }

    boost::gregorian::date scheduler::last_tuesday() const {
        return get_last(boost::date_time::Tuesday);
    }

    boost::gregorian::date scheduler::last_wednesday() const {
        return get_last(boost::date_time::Wednesday);
    }

    boost::gregorian::date scheduler::last_thursday() const {
        return get_last(boost::date_time::Thursday);
    }

    boost::gregorian::date scheduler::last_friday() const {
        return get_last(boost::date_time::Friday);
    }

    boost::gregorian::date scheduler::last_saturday() const {
        return get_last(boost::date_time::Saturday);
    }

    boost::gregorian::date scheduler::last_sunday() const {
        return get_last(boost::date_time::Sunday);
    }
}  // namespace meetup
