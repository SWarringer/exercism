namespace hellmath {

enum class AccountStatus { troll, guest, user, mod };

enum class Action { read, write, remove };

bool display_post(AccountStatus poster, AccountStatus viewer) {
  return (poster == AccountStatus::troll && viewer == AccountStatus::troll) ||
         poster != AccountStatus::troll;
}

bool permission_check(Action action, AccountStatus status) {
  switch (status) {
  case AccountStatus::guest:
    switch (action) {
    case Action::read:
      return true;
    case Action::write:
      return false;
    case Action::remove:
      return false;
    default:
      return false;
    }
  case AccountStatus::user:
    switch (action) {
    case Action::read:
      return true;
    case Action::write:
      return true;
    case Action::remove:
      return false;
    default:
      return false;
    }
  case AccountStatus::troll:
    switch (action) {
    case Action::read:
      return true;
    case Action::write:
      return true;
    case Action::remove:
      return false;
    default:
      return false;
    }
  case AccountStatus::mod:
    switch (action) {
    case Action::read:
      return true;
    case Action::write:
      return true;
    case Action::remove:
      return true;
    default:
      return false;
    }
  default:
    return false;
  }
}

bool valid_player_combination(AccountStatus account1, AccountStatus account2) {
  if (account1 == AccountStatus::troll || account2 == AccountStatus::troll) {
    if (account1 != account2)
      return false;
  }
  if (account1 == AccountStatus::guest || account2 == AccountStatus::guest) {
    return false;
  }
  return true;
}

bool has_priority(AccountStatus account1, AccountStatus account2) {
  switch (account1) {
  case AccountStatus::troll:
    return false;
  case AccountStatus::guest:
    switch (account2) {
    case AccountStatus::user:
      return false;
    case AccountStatus::mod:
      return false;
    case AccountStatus::guest:
      return false;
    default:
      return true;
    }
  case AccountStatus::mod:
    if (account2 == AccountStatus::mod) {
      return false;
    }
    return true;
  case AccountStatus::user:
    switch (account2) {
    case AccountStatus::mod:
      return false;
    case AccountStatus::user:
      return false;
    default:
      return true;
    }
  default:
    return false;
  }
}

} // namespace hellmath
