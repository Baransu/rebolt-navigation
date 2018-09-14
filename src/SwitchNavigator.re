open Rebolt;

module Styles = {
  open Style;
  type textSize =
    | Small
    | Regular;
  let container = style([flex(1.)]);
  let screenContainer =
    style([
      position(Absolute),
      top(Pt(0.)),
      right(Pt(0.)),
      bottom(Pt(0.)),
      left(Pt(0.)),
    ]);
};

module CreateSwitchNavigator = (Config: {type route;}) => {
  module SwitchNavigator = {
    type currentRoute = Config.route;
    type jumpTo = Config.route => unit;

    type screens = array(Config.route);
    type navigation = {
      screens,
      currentRoute,
      jumpTo,
    };

    type action =
      | JumpTo(Config.route);

    type state = {
      screens,
      currentRoute,
    };

    let component = ReasonReact.reducerComponent("SwitchNavigator");
    let make = (~initialRoute, ~routes, children) => {
      ...component,
      initialState: () => {screens: routes, currentRoute: initialRoute},
      reducer: (action, state) =>
        switch (action) {
        | JumpTo(route) =>
          if (route !== state.currentRoute) {
            ReasonReact.Update({...state, currentRoute: route});
          } else {
            ReasonReact.NoUpdate;
          }
        },
      render: self =>
        <SafeAreaView style=Styles.container>
          <View style=Styles.container>
            (
              self.state.screens
              |> Array.mapi((index, screen) =>
                   if (self.state.currentRoute === screen) {
                     <View
                       key=(string_of_int(index))
                       style=Styles.screenContainer
                       pointerEvents=`auto>
                       (
                         children(
                           ~navigation={
                             jumpTo: route => self.send(JumpTo(route)),
                             currentRoute: screen,
                             screens: self.state.screens,
                           },
                         )
                       )
                     </View>;
                   } else {
                     ReasonReact.null;
                   }
                 )
              |> ReasonReact.array
            )
          </View>
        </SafeAreaView>,
    };
    module Screen = {
      let component = ReasonReact.statelessComponent("Screen");
      let make = (~navigation as _, children) => {
        ...component,
        render: _self => <View style=Styles.container> (children()) </View>,
      };
    };
  };
};