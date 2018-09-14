module Config = {
  type route =
    | Welcome
    | Feed
    | Admin
    | Likes
    | Home
    | UserProfile
    | About
    | TabExample
    | ContactList
    | Messages
    | CustomTabBarExample
    | CustomHome
    | CustomMessages
    | CustomProfile
    | CustomProfileDetails
    | CustomProfileStats
    | SwitchExample
    | SwitchFirst
    | SwitchSecond;
};

include StackNavigator.CreateStackNavigator(Config);
include TabNavigator.CreateTabNavigator(Config);
include SwitchNavigator.CreateSwitchNavigator(Config);