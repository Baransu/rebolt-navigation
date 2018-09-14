open Rebolt;

module Styles = {
  open Style;
  let header = style([elevation(0.)]);
};

let component = ReasonReact.statelessComponent("SwitchExample");

let make =
    (
      ~navigation as nav: NavigationConfig.StackNavigator.navigation,
      _children,
    ) => {
  ...component,
  render: _self =>
    <NavigationConfig.StackNavigator.Screen
      headerTitle="SwitchExample" headerStyle=Styles.header navigation=nav>
      ...(
           () =>
             <NavigationConfig.SwitchNavigator
               initialRoute=NavigationConfig.Config.SwitchFirst
               routes=[|
                 NavigationConfig.Config.SwitchFirst,
                 NavigationConfig.Config.SwitchSecond,
               |]>
               ...(
                    (~navigation) =>
                      switch (navigation.currentRoute) {
                      | NavigationConfig.Config.SwitchFirst =>
                        <SwitchFirst navigation />
                      | NavigationConfig.Config.SwitchSecond =>
                        <SwitchSecond navigation />
                      | _ =>
                        Js.log("other case");
                        ReasonReact.null;
                      }
                  )
             </NavigationConfig.SwitchNavigator>
         )
    </NavigationConfig.StackNavigator.Screen>,
};