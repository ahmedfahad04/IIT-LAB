`https://refactoring.guru/design-patterns/mediator/java/example#example-0--mediator-Mediator-java`

`Implementation GUIDE:`

* We'll have a component interface and a Mediator interface where common method for communicating with mediator will
be present in components interface.

* Component.java
  * `public interface Component {
    void setMediator(Mediator mediator);
    String getName();
    }`
* Mediator.java
  * `public interface Mediator {
    void addNewNote(Note note);
    void deleteNote();
    void getInfoFromList(Note note);
    void saveChanges();
    void markNote();
    void clear();
    void sendToFilter(ListModel listModel);
    void setElementsList(ListModel list);
    void registerComponent(Component component);
    void hideElements(boolean flag);
    void createGUI();
    }`

* Then the concrete implementation will provide necessary
implementations of inter

* AddButton.java
  * `public class AddButton extends JButton implements Component {
    private Mediator mediator;

    public AddButton() {
    super("Add");
    }

    @Override
    public void setMediator(Mediator mediator) {
    this.mediator = mediator;
    }

    @Override
    protected void fireActionPerformed(ActionEvent actionEvent) {
    **mediator.addNewNote(new Note());**
    }

    @Override
    public String getName() {
    return "AddButton";
    }
    }
    `
* Editor.java
  * ```public class Editor implements Mediator {
    private Title title;
    private TextBox textBox;
    private AddButton add;
    private DeleteButton del;
    private SaveButton save;
    private List list;
    private Filter filter;

    private JLabel titleLabel = new JLabel("Title:");
    private JLabel textLabel = new JLabel("Text:");
    private JLabel label = new JLabel("Add or select existing note to proceed...");

    /**
    * Here the registration of components by the mediator.
      */
      @Override
      public void registerComponent(Component component) {
      component.setMediator(this);
      switch (component.getName()) {
      case "AddButton":
      add = (AddButton)component;
      break;
      case "DelButton":
      del = (DeleteButton)component;
      break;
      case "Filter":
      filter = (Filter)component;
      break;
      case "List":
      list = (List)component;
      this.list.addListSelectionListener(listSelectionEvent -> {
      Note note = (Note)list.getSelectedValue();
      if (note != null) {
      getInfoFromList(note);
      } else {
      clear();
      }
      });
      break;
      case "SaveButton":
      save = (SaveButton)component;
      break;
      case "TextBox":
      textBox = (TextBox)component;
      break;
      case "Title":
      title = (Title)component;
      break;
      }
      }

    /**
    * Various methods to handle requests from particular components.
      */
      @Override
      public void addNewNote(Note note) {
      title.setText("");
      textBox.setText("");
      list.addElement(note);
      }``
    .
    .
    .
      `