/**
 * @author Lorenzo Cauli
 * @version 0.1
 */
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/*
    - root: TreeNode

    + Albero()

    + caricaAlbero(in f: File): void
    - caricaAlbero(in sc: Scanner): TreeNode

    + toString(): String
    - toString(in node: TreeNode): String

    + contaFoglie(): String
    - contaFoglie(in node: TreeNode): String
    
    + contaNodi(): String
    - contaNodi(in node: TreeNode): String
    
    + ricerca(in query: String): TreeNode
    - ricerca(in node: TreeNode, query: String): TreeNode

    + getRoot(): TreeNode
    + merge(Albero gen2, String newRoot): void
*/

public class Albero {
    private TreeNode root;
    
    public Albero() {
        root = null;
    }

    /**
     * Metodo pubblico per caricare l'albero
     * @param f Oggetto file sorgente
     * @throws FileNotFoundException
     */
    public void caricaAlbero(File f) throws FileNotFoundException{
        try {
            Scanner sc = new Scanner(f);
            caricaAlbero(sc);
        }
        catch (FileNotFoundException e) {
            throw new FileNotFoundException("File non trovato.");
        }
        catch (NullPointerException e) {
            throw new NullPointerException("Errore lettura file.");
        }
    }

    /**
     * Metodo privato per caricare l'albero
     * @param sc Oggetto scanner dal quale prendere gli elementi
     * @return TreeNode caricato
     */
    private void caricaAlbero(Scanner sc) {
        String firstField, secondField, thirdField;
        while (sc.hasNext()) {
            firstField = sc.next();
            secondField = sc.next();
            thirdField = sc.next();
            if (firstField.equals(".")) {
                root = new TreeNode(new String(secondField));
            }
            else {
                TreeNode father = ricerca(root, firstField);
                String childName = secondField;
                String childPos = thirdField;
                if (childPos.equals("s")) {
                    father.setLeft(new TreeNode(childName));
                }
                else if (childPos.equals("d")) {
                    father.setRight(new TreeNode(childName));
                }
            }
        }
    }

    /**
     * Metodo pubblico per la visita anticipata. Stampa l'albero
     * @return Stringa contenente lo stato dell'oggetto
     */
    public String toString() {
        String out = "";
        out += toString(root);
        return out;
    }

    /**
     * Controparte privata toString
     * @param node Nodo da stampare
     * @return Stringa contenente lo stato del sottoalbero con node come radice
     */
    private String toString(TreeNode node) {
        String out = "";
        if (node != null) {
            out += " " + node.toString() + " ";
            out += toString(node.getLeft());
            out += toString(node.getRight());
        }
        return out;
    }

    /**
     * Metodo che conta le foglie (simile a size() per le liste)
     * @return Il numero di nodi nell'albero
     */
    public int contaFoglie() {
        int out = 0;
        out = contaFoglie(root);
        return out;
    }

    /**
     * Controparte privata contaFoglie
     * @param node Nodo da contare
     * @return Numero di foglie del sottoalbero con node come radice
     */
    private int contaFoglie(TreeNode node) {
		int out = 0;
		if (node != null) {
			if (node.getLeft() == null && node.getRight() == null) out = 1;
			else {
				out += contaFoglie(node.getLeft());
				out += contaFoglie(node.getRight());
			}
		}
        return out;
    }

    /**
     * Metodo che conta i nodi (simile a size() per le liste)
     * @return Il numero di nodi nell'albero
     */
    public int contaNodi() {
        return contaNodi(root);
    }

    /**
     * Controparte privata contaNodi
     * @param node Nodo da contare
     * @return Numero di nodi del sottoalbero con node come radice
     */
    private int contaNodi(TreeNode node) {
        int out = 0;
        if (node != null) {
            out++;
            out += contaNodi(node.getLeft());
            out += contaNodi(node.getRight());
        }
        return out;
    }

    /**
     * Metodo per cercare un nodo
     * @param query Stringa da cercare nell'albero
     * @return Nodo trovato
     */
    public TreeNode ricerca(String query) {
        return ricerca(root, query);
    }

    /**
     * Controparte privata ricerca
     * @param node Nodo su cui effettuare la ricerca
     * @param query Stringa da cercare
     * @return Nodo trovato
     */
    private TreeNode ricerca(TreeNode node, String query) {
        TreeNode out = null;
        if (node != null) {
            if (node.getVal().equals(query)) {
                out = node;
            }
            else {
                TreeNode leftRes = ricerca(node.getLeft(), query);
                if (leftRes == null) {
                    TreeNode rightRes = ricerca(node.getRight(), query);
                    if (rightRes != null) {
                        out = rightRes;
                    }
                } else out = leftRes;
            }
        }
        return out;
    }

    /**
     * Getter radice
     * @return Riferimento alla radice
     */
    public TreeNode getRoot() {
        return root;
    }

    /**
     * Metodo che fonde due alberi con un nuovo nato
     * @param gen2 Albero secondo genitore
     * @param newRoot Nome del nuovo figlio
     */
    public void merge(Albero gen2, String newRoot) {
        TreeNode out = new TreeNode(newRoot);
        out.setLeft(root);
        out.setRight(gen2.getRoot());
        root = out;
    }
}
