namespace hellmath
{

    // Task 1 - Define an `AccountStatus` enumeration to represent the four
    // account types: `troll`, `guest`, `user`, and `mod`.
    enum AccountStatus
    {
        mod = 0,
        user = 1,
        guest = 2,
        troll = 3
    };

    // Task 1 - Define an `Action` enumeration to represent the three
    // permission types: `read`, `write`, and `remove`.
    enum Action
    {
        read,
        write,
        remove
    };

    // Task 2 - Implement the `display_post` function, that gets two arguments
    // of `AccountStatus` and returns a `bool`. The first argument is the status of
    // the poster, the second one is the status of the viewer.
    bool display_post(const AccountStatus poster_status, const AccountStatus viewer_status)
    {
        if (poster_status == AccountStatus::troll)
        {
            return viewer_status == AccountStatus::troll;
        }
        return viewer_status != AccountStatus::troll;
    }

    // Task 3 - Implement the `permission_check` function, that takes an
    // `Action` as a first argument and an `AccountStatus` to check against. It
    // should return a `bool`.
    bool permission_check(const Action action, const AccountStatus status)
    {
        switch (status)
        {
        case AccountStatus::mod:
            return true;
            break;
        case AccountStatus::guest:
            return action == Action::read;
            break;
        default:
            return action != Action::remove;
            break;
        }
    }

    // Task 4 - Implement the `valid_player_combination` function that
    // checks if two players can join the same game. The function has two parameters
    // of type `AccountStatus` and returns a `bool`.
    bool valid_player_combination(const AccountStatus player_a, const AccountStatus player_b)
    {
        if (player_a == AccountStatus::guest || player_b == AccountStatus::guest)
        {
            return false;
        }

        if (player_a == AccountStatus::troll && player_b == AccountStatus::troll)
        {
            return true;
        }

        return player_a != AccountStatus::troll && player_b != AccountStatus::troll;
    }

    // Task 5 - Implement the `has_priority` function that takes two
    // `AccountStatus` arguments and returns `true`, if and only if the first
    // account has a strictly higher priority than the second.
    bool has_priority(const AccountStatus account_a, const AccountStatus account_b)
    {
        return account_a < account_b;
    }

} // namespace hellmath